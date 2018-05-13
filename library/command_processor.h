// command_processor.h in Otus homework#7 project

#pragma once

#include <memory>
#include "input_reader.h"
#include "input_processor.h"
#include "smart_buffer.h"
#include "publisher.h"
#include "logger.h"


class CommandProcessor
{
public:

  CommandProcessor
  (
    std::istream& inputStream,
    std::ostream& outputStream,
    const size_t& bulkSize,
    const char& bulkOpenDelimiter,
    const char& bulkCloseDelimiter
   );

  /// Runs input reader
  void run() const ;

  SmartBuffer<std::string>* getCommandBuffer()
  { return inputBuffer.get(); }

  SmartBuffer<std::pair<size_t, std::string>>* getBulkBuffer()
  { return outputBuffer.get(); }

private:
  std::shared_ptr<SmartBuffer<std::string>> inputBuffer;
  std::shared_ptr<SmartBuffer<std::pair<size_t, std::string>>> outputBuffer;
  std::shared_ptr<InputReader> inputReader;
  std::shared_ptr<InputProcessor> inputProcessor;
  std::shared_ptr<Logger> logger;
  std::shared_ptr<Publisher> publisher;
};

