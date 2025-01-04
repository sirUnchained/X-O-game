#include <iostream>
#include <array>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <limits>
#include <random>

void cleanInput();
char check_winner();
bool fill_house(char pc_side, int house);
void show_board(int round);
int pc_chose_house();
void congratulations(char result, char user_side);

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

    if (!std::cin)
    {
      cleanInput();
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
    {
      show_board(i);
      break;
    }
    show_board(i);

    bool pc_input_result{false};
    while (!pc_input_result)
    {
      pc_input_result = fill_house(pc_side, pc_chose_house());
    }
    if (check_winner() != 'c')
    {
      show_board(i);
      break;
    }
    show_board(i);
  }

  std::cout << "\nFinall result:\n";
  show_board(0);

  congratulations(check_winner(), user_side);
}

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

int pc_chose_house()
{
  std::this_thread::sleep_for(std::chrono::microseconds(255));
  std::srand(std::chrono::system_clock::now().time_since_epoch().count());
  int chosed = rand() % 9 + 1;
  return chosed;
}

char check_winner()
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

void show_board(int round)
{
  round > 0 && std::cout << "Round \"" << round << "\" :\n";
  for (int i = 0; i < size(board); i++)#include <iostream>
#include <array>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <limits>
#include <random>

void cleanInput();
char check_winner();
bool fill_house(char pc_side, int house);
void show_board(int round);
int pc_chose_house();
void congratulations(char result, char user_side);

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

    if (!std::cin)
    {
      cleanInput();
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
    {
      show_board(i);
      break;
    }
    show_board(i);

    bool pc_input_result{false};
    while (!pc_input_result)
    {
      pc_input_result = fill_house(pc_side, pc_chose_house());
    }
    if (check_winner() != 'c')
    {
      show_board(i);
      break;
    }
    show_board(i);
  }

  std::cout << "\nFinall result:\n";
  show_board(0);

  congratulations(check_winner(), user_side);
}

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

int pc_chose_house()
{
  std::this_thread::sleep_for(std::chrono::microseconds(255));
  std::srand(std::chrono::system_clock::now().time_since_epoch().count());
  int chosed = rand() % 9 + 1;
  return chosed;
}

char check_winner()
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

void cleanInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

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

void cleanInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
