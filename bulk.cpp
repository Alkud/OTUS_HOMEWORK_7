#include <iostream>
#include "command_processor.h"

int main(int argc, char* argv[])
{
  size_t bulkSize{argc >= 2 ? std::atoi(argv[1]) : 3};
  const CommandProcessor processor{std::cin, std::cout, bulkSize, '{', '}'};
  try
  {
    processor.run();
  }
  catch(const std::exception& ex)
  {
    std::cout << ex.what();
  }
  return 0;
}
