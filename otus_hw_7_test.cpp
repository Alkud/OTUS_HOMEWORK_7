// otus_hw_7_test.cpp in Otus homework#7 project

#define BOOST_TEST_MODULE OTUS_HW_7_TEST

#include <boost/test/unit_test.hpp>
#include "homework_7.h"
#include "command_processor.h"


#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <chrono>
#include <thread>

/* Helper function */
std::vector<std::string> getProcessorOutput
(
  const std::string& inputString,
  char openDelimiter,
  char closeDelimiter,
  size_t bulkSize,
  bool debugOutput
)
{
  std::stringstream inputStream{inputString};
  std::stringstream outputStream{};

  const CommandProcessor testProcessor
  {
    inputStream, outputStream, bulkSize, openDelimiter, closeDelimiter
  };

  testProcessor.run();

  std::string tmpString{};
  std::vector<std::string> result {};
  while(std::getline(outputStream, tmpString))
  {
    if (debugOutput)
    {
      std::cout << tmpString << '\n';
    }
    result.push_back(tmpString);
  }
  return result;
}

BOOST_AUTO_TEST_SUITE(homework_7_test)

BOOST_AUTO_TEST_CASE(objects_creation_failure)
{
  /* can't create input reader with null buffer pointer */
  BOOST_CHECK_THROW((InputReader{std::cin, nullptr}), std::invalid_argument);
  /* can't create publisher with null buffer pointer */
  BOOST_CHECK_THROW((Publisher{nullptr, std::cout}), std::invalid_argument);
  /* can't create logger with null buffer pointer */
  BOOST_CHECK_THROW((Logger{nullptr, ""}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(log_file_creation_failure)
{
  SmartBuffer<std::pair<size_t, std::string>> bulkBuffer;
  std::stringstream outputStream{};
  std::string badDirectoryName{"/non_existing_directory/"};

  /* use bad directory name as constructor parameter */
  Logger badLogger{&bulkBuffer, badDirectoryName, outputStream};
  /* connect buffer to logger */
  bulkBuffer.addNotificationListener(&badLogger);
  /* putting some data to the buffer results in error message */
  bulkBuffer.put(std::make_pair<size_t, std::string>(1234, "bulk"));

  /* build log file name to check error message */
  std::string logFileName
  {
    badDirectoryName.append(std::string{"1234.log"})
  };

  /* build error message */
  std::stringstream errorMessage{};
  errorMessage << "Cannot create log file " << logFileName << " !" << std::endl;

  BOOST_CHECK(outputStream.str() == errorMessage.str());
}

BOOST_AUTO_TEST_CASE(trying_get_from_empty_buffer)
{
  SmartBuffer<std::pair<size_t, std::string>> emptyBuffer;
  /* emptyBuffer.get() should throw an exception */
  BOOST_CHECK_THROW((emptyBuffer.get()), std::out_of_range);
}


BOOST_AUTO_TEST_CASE(no_command_line_parameter)
{
  try
  {
    std::stringstream inputStream{"-1\n2\n"};
    std::stringstream outputStream{};
    char* arg[]{"/home/user/bulk"};
    homework(1, arg, inputStream, outputStream);

    BOOST_CHECK(outputStream.str() ==
                "\nPlease enter bulk size (must be greater than 0): "
                "\nPlease enter bulk size (must be greater than 0): ");
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what();
  }
}

BOOST_AUTO_TEST_CASE(bad_command_line_parameter)
{
  try
  {
    std::stringstream inputStream{"3\n"};
    std::stringstream outputStream{};
    char* arg[]{"/home/user/bulk", "-s"};
    homework(2, arg, inputStream, outputStream);

    BOOST_CHECK(outputStream.str() ==
                "\nOnly integer numbers are allowed"
                "\nPlease enter bulk size (must be greater than 0): ");
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what();
  }
}

BOOST_AUTO_TEST_CASE(wrong_command_line_parameter)
{
  try
  {
    std::stringstream inputStream{"3"};
    std::stringstream outputStream{};
    char* arg[]{"/home/user/bulk", "-10"};
    homework(2, arg, inputStream, outputStream);

    BOOST_CHECK(outputStream.str() ==
                "\nPlease enter bulk size (must be greater than 0): ");
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what();
  }
}

BOOST_AUTO_TEST_CASE(empty_input_test)
{
  try
  {
    auto processorOutput
    {
      getProcessorOutput(std::string{}, '{', '}', 0, false)
    };
    BOOST_CHECK(processorOutput.size() == 0);
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what();
  }
}

BOOST_AUTO_TEST_CASE(empty_command_test)
{
  std::string testString1{"cmd1\n\ncmd2\ncmd3\ncmd4"};
  try
  {
    auto processorOutput
    {
      getProcessorOutput(std::string{}, '{', '}', 0, false)
    };
    BOOST_CHECK(processorOutput.size() == 0);
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what();
  }
}

BOOST_AUTO_TEST_CASE(bulk_segmentation_test1)
{
  try
  {
    std::string testString1{"cmd1\ncmd2\ncmd3\ncmd4"};
    auto processorOutput
    {
      getProcessorOutput(testString1, '{', '}', 3, false)
    };

    BOOST_CHECK(processorOutput.size() == 2);
    BOOST_CHECK(processorOutput[0] == "bulk: cmd1, cmd2, cmd3");
    BOOST_CHECK(processorOutput[1] == "bulk: cmd4");
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what();
  }
}

BOOST_AUTO_TEST_CASE(bulk_segmentation_test2)
{
  try
  {
    std::string testString1
    {
      "cmd1\n"
      "<\n"
      "cmd2\n"
      "cmd3\n"
      ">\n"
      "cmd4"
    };
    auto processorOutput
    {
      getProcessorOutput(testString1, '<', '>', 3, false)
    };

    BOOST_CHECK(processorOutput.size() == 3);
    BOOST_CHECK(processorOutput[0] == "bulk: cmd1");
    BOOST_CHECK(processorOutput[1] == "bulk: cmd2, cmd3");
    BOOST_CHECK(processorOutput[2] == "bulk: cmd4");
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what();
  }
}

BOOST_AUTO_TEST_CASE(nested_bulks_test)
{
  try
  {
    std::string testString1
    {
      "cmd1\n"
      "cmd2\n"
      "cmd3\n"
      "(\n"
        "cmd4\n"
        "cmd5\n"
        "(\n"
          "cmd6\n"
          "(\n"
              "cmd7\n"
          ")\n"
          "cmd8\n"
        ")\n"
        "cmd9\n"
      ")\n"
      "cmd10\n"
      "cmd11\n"
      "cmd12\n"
      "cmd13\n"
    };
    auto processorOutput
    {
      getProcessorOutput(testString1, '(', ')', 4, false)
    };

    BOOST_CHECK(processorOutput.size() == 3);
    BOOST_CHECK(processorOutput[0] ==
                "bulk: cmd1, cmd2, cmd3");
    BOOST_CHECK(processorOutput[1] ==
                "bulk: cmd4, cmd5, cmd6, cmd7, cmd8, cmd9");
    BOOST_CHECK(processorOutput[2] ==
                "bulk: cmd10, cmd11, cmd12, cmd13");
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what();
  }
}

BOOST_AUTO_TEST_CASE(unexpected_bulk_end_test)
{
  try
  {
    std::string testString1
    {
      "cmd1\n"
      "cmd2\n"
      "cmd3\n"
      "(\n"
        "cmd4\n"
        "cmd5\n"
        "(\n"
          "cmd6\n"
          "(\n"
            "cmd7\n"
            "cmd8\n"
          ")\n"
          "cmd9\n"
        ")\n"
        "cmd10\n"
        "cmd11\n"
        "cmd12\n"
        "cmd13\n"
    };
    auto processorOutput
    {
      getProcessorOutput(testString1, '(', ')', 4, false)
    };

    BOOST_CHECK(processorOutput.size() == 1);
    BOOST_CHECK(processorOutput[0] ==
                "bulk: cmd1, cmd2, cmd3");
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what();
  }
}

BOOST_AUTO_TEST_CASE(incorrect_closing_test)
{
  try
  {
    std::string testString1
    {
      "cmd1\n"
      "cmd2\n"
      "cmd3\n"
      "(\n"
        "cmd4\n"
        "cmd5\n"
      ")\n"
      "cmd6\n"
      ")\n"
      "cmd7\n"
      "cmd8\n"
    };
    auto processorOutput
    {
      getProcessorOutput(testString1, '(', ')', 4, false)
    };

    BOOST_CHECK(processorOutput.size() == 3);
    BOOST_CHECK(processorOutput[0] ==
                "bulk: cmd1, cmd2, cmd3");
    BOOST_CHECK(processorOutput[1] ==
                "bulk: cmd4, cmd5");
    BOOST_CHECK(processorOutput[2] ==
                "bulk: cmd6, cmd7, cmd8");

  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what();
  }
}

BOOST_AUTO_TEST_CASE(logging_test)
{
  try
  {
    /* wait second to get separate log file for this test */
    std::this_thread::sleep_for(std::chrono::seconds{1});
    /* get current time */
    std::chrono::time_point<std::chrono::system_clock>
    bulkStartTime{std::chrono::system_clock::now()};
    /* convert bulk start time to integer ticks count */
    auto ticksCount
    {
      std::chrono::duration_cast<std::chrono::seconds>
      (
        bulkStartTime.time_since_epoch()
      ).count()
    };
    /* build log file name */
    std::string logFileName
    {
      std::to_string(ticksCount).append(".log")
    };

    std::ifstream logFile(logFileName, std::ios::app);

    std::string testString1
    {
      "cmd1\n"
      "cmd2\n"
      "cmd3\n"
      "cmd4\n"
      "cmd5\n"
      "cmd6\n"
      "cmd7\n"
      "cmd8\n"
    };
    auto processorOutput
    {
      getProcessorOutput(testString1, '(', ')', 8, false)
    };

    std::string testString2{};
    std::getline(logFile, testString2);

    BOOST_CHECK(processorOutput.size() == 1);
    BOOST_CHECK(processorOutput[0] ==
                "bulk: cmd1, cmd2, cmd3, cmd4, cmd5, cmd6, cmd7, cmd8");
    BOOST_CHECK(logFile);
    BOOST_CHECK(testString2 ==
                "bulk: cmd1, cmd2, cmd3, cmd4, cmd5, cmd6, cmd7, cmd8");
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what();
  }
}



BOOST_AUTO_TEST_SUITE_END()
