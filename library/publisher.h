// publisher.h in Otus homework#7 project

#pragma once

#include "listeners.h"
#include "smart_buffer.h"
#include <iostream>
#include <memory>

class Publisher : public NotificationListener,
                  public std::enable_shared_from_this<Publisher>
{
public:

  Publisher(std::shared_ptr<SmartBuffer<std::pair<size_t, std::string>>> newBuffer, std::ostream& streamToPublish);

  void reactNotification(NotificationBroadcaster* sender) override;

private:

  std::shared_ptr<SmartBuffer<std::pair<size_t, std::string>>> buffer;
  std::ostream& outputStream;
};
