#include <iostream>
#include <array>

char check_winner(const std::array<std::array<char, 3>, 3> &board);
bool fill_house(char side, std::array<std::array<char, 3>, 3> &board);
void show_board(const std::array<std::array<char, 3>, 3> &board, int round);

int main(int argc, char *argv[])
{
  std::array<std::array<char, 3>, 3> board{{
      {'1', '2', '3'},
      {'4', '5', '6'},
      {'7', '8', '9'},
  }};

  char user_side;
  std::cout << "Welcome to our X-O game !\n";

  while (user_side != 'X' && user_side != 'O')
  {
    std::cout << "Please only select one of these \"X\" or \"O\"\n";
    std::cin >>
        user_side;
    user_side = (char)toupper(user_side);

    if (std::cin.fail())
    {
      std::cerr << "Invalid input, process terminated.";
      exit(1);
    }
  }

  char pc_side = user_side == 'X' ? 'O' : 'X';

  std::cout << "\nYou are \"" << user_side << "\".\nI am \"" << pc_side << "\".\nNOW LETS PLAY !\n\n";

  for (int i = 1; check_winner(board) == 'c'; i++)
  {
    show_board(board, i);
    fill_house(user_side, board);
  }

  std::cout << check_winner(board);
}

char check_winner(const std::array<std::array<char, 3>, 3> &board)
{
  for (int i = 0; i < size(board); i++)
  {
    for (int j = 0; j < size(board); j++)
    {
      if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j])
      {
        return board[i][j];
      }
      else if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2])
      {
        return board[i][j];
      }
      else if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2])
      {
        return board[i][j];
      }
      else if (board[i][j + 2] == board[i + 1][j + 1] && board[i][j + 2] == board[i][j])
      {
        return board[i][j];
      }
    }
  }
  return 'c';
}

bool fill_house(char side, std::array<std::array<char, 3>, 3> &board)
{
  int house{0};
  std::cout << "Which house you wanna fill : ";
  std::cin >> house;
  if (house > 9 || house < 0)
  {
    std::cout << "Out of Houses ! enter a valid one.\n";
    return false;
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
          std::cout << "\nThe house is already filled with \"" << board[i][j] << "\".\n";
          return false;
        }
        board[i][j] = side;
        return true;
      }
    }
  }
  return false;
}

void show_board(const std::array<std::array<char, 3>, 3> &board, int round)
{
  std::cout << "Round \"" << round << "\" :\n";
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
