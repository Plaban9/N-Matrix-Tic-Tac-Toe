#include <iostream>
#include <string>
#include "TicTacToe.hpp"

int main()
{
	Game::TicTacToe game(3, false);

	game.playGame();

	std::cout << "\nThank You for Playing!!";
	system("PAUSE>null");

	return 0;
}