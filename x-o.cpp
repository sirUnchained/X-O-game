#include <iostream>
#include <array>

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

  for (int i = 1; check_winner(board) != 'n'; i++)
  {
    show_board(board, i);
    fill_house(user_side, board);
  }

  std::cout << check_winner(board);
}
