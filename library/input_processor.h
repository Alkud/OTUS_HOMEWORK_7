// input_processor.h in Otus homework#7 project

#pragma once

#include "smart_buffer.h"
#include <memory>
#include <chrono>
#include <ctime>


class InputProcessor : public NotificationListener,
                       public MessageListener
{
public:
  InputProcessor(size_t newBulkSize,
                 char newBulkOpenDelimiter,
                 char newBulkCloseDelimiter,
                 SmartBuffer<std::string>* newInputBuffer,
                 SmartBuffer<std::pair<size_t, std::string>>* newOutputBuffer);

  void reactNotification(NotificationBroadcaster* sender) override;

  void reactMessage(MessageBroadcaster* sender, std::string message) override;


private:

  friend class BulkProcessorCreator;

  void sendCurrentBulk();
  void startNewBulk();
  void closeCurrentBulk();
  void addCommandToBulk(std::string&& newCommand);

  size_t bulkSize;
  std::string bulkOpenDelimiter;
  std::string bulkCloseDelimiter;
  SmartBuffer<std::string>* inputBuffer;
  SmartBuffer<std::pair<size_t, std::string>>* outputBuffer;

  std::deque<std::string> tempBuffer;
  bool customBulkStarted;
  size_t nestingDepth;
  std::chrono::time_point<std::chrono::system_clock> bulkStartTime;
};
