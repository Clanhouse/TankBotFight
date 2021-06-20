#include "Board.hpp"
#include <thread>

int
main()
{
  Board b;
  std::jthread main(&Board::run, &b);
  return 0;
}
