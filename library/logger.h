// logger.h in Otus homework#7 project

#pragma once

#include "listeners.h"
#include "smart_buffer.h"
#include <chrono>

class Logger : public NotificationListener
{
public:
  Logger(SmartBuffer<std::pair<size_t, std::string>>* newBuffer);

  void reactNotification(NotificationBroadcaster* sender) override ;

private:

  friend class BulkProcessorCreator;

  SmartBuffer<std::pair<size_t, std::string>>* buffer;
};

