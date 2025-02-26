#include <iostream>
#include <array>
#include <limits>
#include <random>

#include "print_dir/include/print_funcs.h"
#include "action_dir/include/action_funcs.h"

void cleanInput();

std::mt19937 random_nums{std::random_device{}()};
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
			cleanInput();
	}

	char pc_side = user_side == 'X' ? 'O' : 'X';

	std::cout << "\nYou are \"" << user_side << "\".\nI am \"" << pc_side << "\".\nNOW LETS PLAY !\n\n";

	show_board(0, board);
	for (int i = 1; check_winner(board) == 'c'; i++)
	{
		bool user_input_result{false};
		while (!user_input_result)
		{
			user_input_result = fill_house(user_side, 0);
		}
		if (check_winner(board) != 'c')
		{
			show_board(i, board);
			break;
		}
		show_board(i, board);

		bool pc_input_result{false};
		while (!pc_input_result)
		{
			pc_input_result = fill_house(pc_side, pc_chose_house(random_nums));
		}
		if (check_winner(board) != 'c')
		{
			show_board(i, board);
			break;
		}
		show_board(i, board);
	}

	std::cout << "\nFinall result:\n";
	show_board(0, board);

	congratulations(check_winner(board), user_side);
}

void cleanInput()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
