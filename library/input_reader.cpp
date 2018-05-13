// input_reader.cpp in Otus homework#7 project

#include "input_reader.h"
#include <string>
#include <stdexcept>

InputReader::InputReader(std::istream& newInput, std::shared_ptr<SmartBuffer<std::string> > newBuffer) :
  input{newInput},
  buffer{newBuffer}
{
  if (nullptr == buffer)
  {
    throw(std::invalid_argument{"Input reader destination buffer not defined!"});
  }
}

void InputReader::read()
{
  std::string nextString{};
  try
  {
    while(std::getline(input, nextString))
    {
      if (nextString.size() > (size_t)InputReaderSettings::MaxInputStringSize)
      {
        std::cerr << "Maximum command length exceeded! String truncated";
        nextString = nextString.substr((size_t)InputReaderSettings::MaxInputStringSize);
      }
      buffer->putItem(std::move(nextString));
    }
  }
  catch(std::exception& ex)
  {
    sendMessage(std::string{"STOP"});
    throw;
  }
  sendMessage(std::string{"STOP"});
}
