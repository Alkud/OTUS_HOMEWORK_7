// command_processor.cpp in Otus homework#7 project

#include "command_processor.h"

CommandProcessor::CommandProcessor
(
  std::istream& inputStream,
  std::ostream& outputStream,
  size_t bulkSize,
  char bulkOpenDelimiter,
  char bulkCloseDelimiter
 ) :
  /* creating buffers */
  inputBuffer{std::make_shared<SmartBuffer<std::string>>()},
  outputBuffer{std::make_shared<SmartBuffer<std::pair<size_t, std::string>>>()},
  /* creating command reader */
  inputReader{std::make_shared<InputReader>(inputStream, inputBuffer)},
  /* creating command processor */
  inputProcessor{
    std::make_shared<InputProcessor>
    (
      bulkSize,
      bulkOpenDelimiter, bulkCloseDelimiter,
      inputBuffer, outputBuffer
    )
  },
  /* creating logger */
  logger{std::make_shared<Logger>(outputBuffer)},
  /* creating publisher */
  publisher{std::make_shared<Publisher>(outputBuffer, outputStream)}

{
  /* connect broadcasters and listeners */
  inputReader->addMessageListener(inputProcessor);
  inputBuffer->addNotificationListener(inputProcessor);
  outputBuffer->addNotificationListener(logger);
  outputBuffer->addNotificationListener(publisher);
}

void CommandProcessor::run() const
{
  if (inputReader != nullptr)
  {
    inputReader->read();
  }
}
