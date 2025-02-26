#include <iostream>
#include <limits>
#include <random>
#include <array>

int pc_chose_house(std::mt19937 random_nums);
char check_winner(std::array<std::array<char, 3>, 3> &board);
bool fill_house(char side, int chosenHouse = 0, std::array<std::array<char, 3>, 3> &board);
