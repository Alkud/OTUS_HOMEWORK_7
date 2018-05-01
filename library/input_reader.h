// input_reader.h in Otus homework#7 project

#pragma once

#include "broadcasters.h"
#include "smart_buffer.h"
#include <iostream>
#include <memory>

class InputReader : public MessageBroadcaster
{
public:
  InputReader(std::istream& newInput, SmartBuffer<std::string>* newBuffer);

  /// Read from input stream until eof
  void read();

private:
  std::istream& input;
  SmartBuffer<std::string>* buffer;
};
