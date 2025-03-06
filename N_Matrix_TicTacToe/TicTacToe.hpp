#pragma once

namespace Game
{
	class TicTacToe
	{
	private:
		static bool WEAVE_BOARD_DISPLAY;
		static int MAX_SIZE;
		static int MAX_MOVES;

		char** _board;
		void initializeBoard();
		void clearBoard();
		void printBoard();
		void validateCoordinate(int row, int column, char symbol);
		int winCheck(char symbol);
		bool rowCheck(char symbol);
		bool columnCheck(char symbol);
		bool diagonalCheck(char symbol);
		bool leftDiagonalCheck(char symbol);
		bool rightDiagonalCheck(char symbol);

	public:
		TicTacToe(int maxSize = 3, bool isWeaveDisplay = true);

		void playGame();

		~TicTacToe();
	};
}

