// publisher.cpp in Otus homework#7 project

#include "publisher.h"


Publisher::Publisher(std::shared_ptr<SmartBuffer<std::pair<size_t, std::string> > > newBuffer, std::ostream& streamToPublish) :
  buffer{newBuffer}, outputStream{streamToPublish}
{
  if (nullptr == buffer)
  {
    throw(std::invalid_argument{"Publisher source buffer not defined!"});
  }
}

void Publisher::reactNotification(NotificationBroadcaster* sender)
{
  if (buffer.get() == sender)
  {
    auto nextBulkInfo{buffer->getItem(shared_from_this())};
    outputStream << nextBulkInfo.second << '\n';
  }
}
