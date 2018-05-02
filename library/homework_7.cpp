// homework_7.cpp in Otus homework#7 project

#include "homework_7.h"
#include "command_processor.h"

void homework(int argc, char* argv[], std::istream& inputStream, std::ostream& outputStream)
{
  int commandLineParam{};
  try
  {
    commandLineParam = argc < 2 ? -1 : std::stoi(argv[1]);
  }
  catch(const std::exception& ex)
  {
    outputStream << "\nOnly integer numbers are allowed";
    commandLineParam = -1;
  }

  std::string userInput{};
  if (commandLineParam < 1)
  {
    while (commandLineParam < 1)
    {
      outputStream << "\nPlease enter bulk size (must be greater than 0): ";
      if (!std::getline(inputStream, userInput))
      {
        outputStream << std::endl;
        return;
      }
      try
      {
        commandLineParam = std::stoi(userInput);
      }
      catch(const std::exception& ex)
      {
        outputStream << "\nOnly integer numbers are allowed";
        commandLineParam = -1;
      }
    }
  }
  size_t bulkSize{commandLineParam};

  const CommandProcessor processor{inputStream, outputStream, bulkSize, '{', '}'};

  processor.run();
}
