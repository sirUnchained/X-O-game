#include <iostream>
#include <limits>
#include <random>
#include <array>

int pc_chose_house();
char check_winner(std::array<std::array<char, 3>, 3> &board);
bool fill_house(char side, std::array<std::array<char, 3>, 3> &board, int chosenHouse);
void cleanInput();
