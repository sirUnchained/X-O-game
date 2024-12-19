#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <windows.h>

char check_winner();
bool fill_house(char pc_side, int house);
void show_board(int round);
int pc_chose_house();

std::array<std::array<char, 3>, 3> board{{
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
}};

int main(int argc, char *argv[])
{
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

  show_board(0);
  for (int i = 1; check_winner() == 'c'; i++)
  {
    bool user_input_result{false};
    while (!user_input_result)
    {
      user_input_result = fill_house(user_side, 0);
    }

    if (check_winner() != 'c')
      break;

    bool pc_input_result{false};
    while (!pc_input_result)
    {
      pc_input_result = fill_house(pc_side, pc_chose_house());
    }
    show_board(i);
  }

  std::cout << check_winner();
}

int pc_chose_house()
{
  _sleep(1000);
  std::srand(std::time(0));
  int chosed = rand() % 9;
  return chosed;
}

char check_winner()
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

bool fill_house(char side, int chosenHouse = 0)
{
  int house{-1};
  house = chosenHouse;
  if (!chosenHouse)
  {
    std::cout << "Which house you wanna fill : ";
    std::cin >> house;
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
          chosenHouse &&std::cout << "\nThe house is already filled with \"" << board[i][j] << "\".\n";
          return false;
        }
        board[i][j] = side;
        return true;
      }
    }
  }
  return false;
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
