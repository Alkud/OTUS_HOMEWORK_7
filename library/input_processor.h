// input_processor.h in Otus homework#7 project

#pragma once

#include "smart_buffer.h"
#include <memory>
#include <chrono>
#include <ctime>


class InputProcessor : public NotificationListener,
                       public MessageListener,
                       public std::enable_shared_from_this<InputProcessor>
{
public:

  InputProcessor(size_t newBulkSize,
                 char newBulkOpenDelimiter,
                 char newBulkCloseDelimiter,
                 std::shared_ptr<SmartBuffer<std::string>> newInputBuffer,
                 std::shared_ptr<SmartBuffer<std::pair<size_t, std::string>>> newOutputBuffer);

  void reactNotification(NotificationBroadcaster* sender) override;

  void reactMessage(MessageBroadcaster* sender, std::string message) override;


private:

  void sendCurrentBulk();
  void startNewBulk();
  void closeCurrentBulk();
  void addCommandToBulk(std::string&& newCommand);

  size_t bulkSize;
  std::string bulkOpenDelimiter;
  std::string bulkCloseDelimiter;
  std::shared_ptr<SmartBuffer<std::string>> inputBuffer;
  std::shared_ptr<SmartBuffer<std::pair<size_t, std::string>>> outputBuffer;

  std::deque<std::string> tempBuffer;
  bool customBulkStarted;
  size_t nestingDepth;
  std::chrono::time_point<std::chrono::system_clock> bulkStartTime;
};
