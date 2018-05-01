// publisher.cpp in Otus homework#7 project

#include "publisher.h"


Publisher::Publisher(SmartBuffer<std::pair<size_t, std::string>>* newBuffer, std::ostream& streamToPublish) :
  buffer{newBuffer}, outputStream{streamToPublish}
{
  if (nullptr == buffer)
  {
    throw(std::invalid_argument{"Publisher source buffer not defined!"});
  }
}

void Publisher::reactNotification(NotificationBroadcaster* sender)
{
  if (buffer == sender)
  {
    auto nextBulkInfo{buffer->get(this)};
    outputStream << nextBulkInfo.second << '\n';
  }
}
