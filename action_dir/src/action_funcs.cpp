#include "include/action_funcs.h"

int pc_chose_house(std::mt19937 random_nums)
{
  int chosed = random_nums() % 9 + 1;
  return chosed;
}

char check_winner(std::array<std::array<char, 3>, 3> &board)
{
  for (int i = 0; i < 3; i++)
  {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
      return board[i][0];
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
      return board[0][i];
  }

  if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
  {
    return board[0][0];
  }
  else if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
  {
    return board[0][2];
  }

  for (const auto &row : board)
  {
    for (const auto &home : row)
    {
      if (home != 'X' && home != 'O')
        return 'c';
    }
  }

  return '=';
}

bool fill_house(char side, int chosenHouse = 0, std::array<std::array<char, 3>, 3> &board)
{
  int house{-1};
  house = chosenHouse;
  std::cout << "Which house you wanna fill : \n";
  if (!chosenHouse)
  {
    std::cin >> house;
    if (!std::cin)
    {
      std::cout << "Invalid inputs, try again.\n";
      // cleanInput();
      return false;
    }

    if (house > 9 || house < 0)
    {
      std::cout << "Out of Houses ! enter a valid one.\n";
      return false;
    }
  }

  int count{0};
  for (int i = 0; i < size(board); i++)
  {
    for (int j = 0; j < size(board); j++)
    {
      count++;
      if (count == house)
      {
        if (board[i][j] == 'X' || board[i][j] == 'O')
        {
          chosenHouse || std::cout << "\nThe house is already filled with \"" << board[i][j] << "\".\n";
          return false;
        }
        board[i][j] = side;
        return true;
      }
    }
  }
  return false;
}