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
    size_t bulkSize,
    char bulkOpenDelimiter,
    char bulkCloseDelimiter
   );

  /// Runs input reader
  void run() const ;

  SmartBuffer<std::string>* getCommandBuffer()
  { return inputBuffer.get(); }
  SmartBuffer<std::pair<size_t, std::string>>* getBulkBuffer()
  { return outputBuffer.get(); }

private:
  std::unique_ptr<InputReader> inputReader;
  std::unique_ptr<SmartBuffer<std::string>> inputBuffer;
  std::unique_ptr<InputProcessor> inputProcessor;
  std::unique_ptr<SmartBuffer<std::pair<size_t, std::string>>> outputBuffer;
  std::unique_ptr<Logger> logger;
  std::unique_ptr<Publisher> publisher;
};

