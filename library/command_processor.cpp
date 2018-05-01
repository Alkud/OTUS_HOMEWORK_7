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
  inputReader{}, inputBuffer{},
  inputProcessor{}, outputBuffer{},
  logger{}, publisher{}
{
  /* creating buffers */
  auto inputBufferPointer{std::make_unique<SmartBuffer<std::string>>()};
  inputBuffer.swap(inputBufferPointer);
  auto outputBufferPointer{std::make_unique<SmartBuffer<std::pair<size_t, std::string>>>()};
  outputBuffer.swap(outputBufferPointer);


  /* creating command reader */
  auto inputReaderPointer {std::make_unique<InputReader>(inputStream, inputBuffer.get())};
  inputReader.swap(inputReaderPointer);

  /* creating command processor */
  auto inputProcessorPointer
  {
    std::make_unique<InputProcessor>
    (
      bulkSize,
      bulkOpenDelimiter, bulkCloseDelimiter,
      inputBuffer.get(), outputBuffer.get()
    )
  };
  inputProcessor.swap(inputProcessorPointer);

  /* creating logger */
  auto loggerPointer{std::make_unique<Logger>(outputBuffer.get())};
  logger.swap(loggerPointer);

  /* creating publisher */
  auto publisherPointer{std::make_unique<Publisher>(outputBuffer.get(), outputStream)};
  publisher.swap(publisherPointer);

  /* connect broadcasters and listeners */
  inputReader->addMessageListener(inputProcessor.get());
  inputBuffer->addNotificationListener(inputProcessor.get());
  outputBuffer->addNotificationListener(logger.get());
  outputBuffer->addNotificationListener(publisher.get());
}

void CommandProcessor::run() const
{
  if (inputReader != nullptr)
  {
    inputReader->read();
  }
}
