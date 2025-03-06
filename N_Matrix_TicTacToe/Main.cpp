#include <iostream>
#include <string>
#include "TicTacToe.hpp"

int main()
{
	Game::TicTacToe game(3, false);	 // Grid Size, Weave Aesthetic Toggle

	game.playGame();

	std::cout << "\nThank You for Playing!!";
	system("PAUSE>null");

	return 0;
}