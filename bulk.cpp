// bulk.cpp in Otus homework#7 project

#include "homework_7.h"
#include <stdexcept>
#include <iostream>

int main(int argc, char* argv[])
{
  try
  {
    homework(argc, argv, std::cin, std::cout);
  }
  catch(const std::exception& ex)
  {
    std::cerr << ex.what();
  }
  return 0;
}
