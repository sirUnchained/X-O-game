#include "print_funcs.h"

void congratulations(char result, char user_side)
{
  if (result == user_side)
  {
    std::cout << "\nWell done you won !.\n";
    return;
  }
  else if (result == '=')
  {
    std::cout << "\nIt was a drow !.\n";
    return;
  }

  std::cout << "\nI won !.\n";
}

void show_board(int round, std::array<std::array<char, 3>, 3> &board)
{
  round > 0 && std::cout << "Round \"" << round << "\" :\n";
  for (int i = 0; i < size(board); i++)
  {
    for (int j = 0; j < size(board); j++)
    {
      std::cout << board[i][j];
      if (j != 2)
        std::cout << '|';
    }
    if (i != 2)
      std::cout << "\n_ _ _\n";
  }
  std::cout << "\n\n";
}
