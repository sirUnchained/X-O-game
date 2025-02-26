#include <iostream>
#include <index.h>

void congratulations(char result, char user_side)
{
  if (result == user_side)
  {
    std::cout << "\nWell done you won !.";
    return;
  }
  else if (result == '=')
  {
    std::cout << "\nIt was a drow !.";
    return;
  }

  std::cout << "\nI won !.";
}

void show_board(int round)
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
