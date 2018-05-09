// logger.h in Otus homework#7 project

#pragma once

#include "listeners.h"
#include "smart_buffer.h"
#include <chrono>
#include <iostream>
#include <memory>

class Logger : public NotificationListener,
               public std::enable_shared_from_this<Logger>
{
public:

  Logger(std::shared_ptr<SmartBuffer<std::pair<size_t, std::string>>> newBuffer,
         const std::string& newDestinationDirectory = "", std::ostream& newErrorOut = std::cerr);

  void reactNotification(NotificationBroadcaster* sender) override ;

private:

  std::shared_ptr<SmartBuffer<std::pair<size_t, std::string>>> buffer;
  std::string destinationDirectory;
  std::ostream& errorOut;
};

