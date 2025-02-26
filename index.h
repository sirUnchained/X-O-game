#include <array>
#include <limits>
#include <random>

std::mt19937 random_nums{std::random_device{}()};
std::array<std::array<char, 3>, 3> board{{
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
}};