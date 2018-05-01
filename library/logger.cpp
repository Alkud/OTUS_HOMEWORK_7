// logger.cpp in Otus homework#7 project

#include "logger.h"
#include <fstream>
#include <iostream>

Logger::Logger(SmartBuffer<std::pair<size_t, std::string>>* newBuffer) :
  buffer{newBuffer}
{
  if (nullptr == buffer)
  {
    throw(std::invalid_argument{"Logger source buffer not defined!"});
  }
}

void Logger::reactNotification(NotificationBroadcaster* sender)
{
  if (buffer == sender)
  {
    auto nextBulkInfo{buffer->get(this)};
    std::string logFileName
    {
      std::to_string(nextBulkInfo.first).append(".log")
    };
    std::ofstream logFile(logFileName, std::ios::app);

    if(!logFile)
    {
        std::cout << "Cannot create log file " <<
                     logFileName << " !" << std::endl;
        return;
    }

    logFile << nextBulkInfo.second << '\n';
    logFile.close();
  }
}
