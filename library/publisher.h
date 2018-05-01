// publisher.h in Otus homework#7 project

#pragma once

#include "listeners.h"
#include "smart_buffer.h"
#include <iostream>

class Publisher : public NotificationListener
{
public:
  Publisher(SmartBuffer<std::pair<size_t, std::string>>* newBuffer, std::ostream& streamToPublish);

  void reactNotification(NotificationBroadcaster* sender) override;

private:

  friend class BulkProcessorCreator;

  SmartBuffer<std::pair<size_t, std::string>>* buffer;
  std::ostream& outputStream;
};
