#include "TicTacToe.hpp"

#include <iostream>
#include <string>


using std::cout;
using std::cin;
using std::string;

namespace Game
{
	bool TicTacToe::WEAVE_BOARD_DISPLAY = true;
	int TicTacToe::MAX_SIZE = 3;
	int TicTacToe::MAX_MOVES = MAX_SIZE * MAX_SIZE;

	TicTacToe::TicTacToe(int maxSize, bool isWeaveDisplay)
	{
		MAX_SIZE = maxSize;
		MAX_MOVES = MAX_SIZE * MAX_SIZE;
		WEAVE_BOARD_DISPLAY = isWeaveDisplay;

		initializeBoard();
		clearBoard();
		printBoard();
	}

	TicTacToe::~TicTacToe()
	{
		for (int i = 0; i < MAX_SIZE; ++i)
		{
			delete[] _board[i];
		}

		delete[] _board;
	}

	void TicTacToe::initializeBoard()
	{
		_board = new char* [MAX_SIZE];

		for (int i = 0; i < MAX_SIZE; ++i)
		{
			_board[i] = new char[MAX_SIZE];
		}
	}

	void TicTacToe::clearBoard()
	{
		for (int i = 0; i < MAX_SIZE; ++i)
		{
			for (int j = 0; j < MAX_SIZE; ++j)
			{
				_board[i][j] = ' ';
			}
		}
	}

	void TicTacToe::printBoard()
	{
		system("cls");

		cout << "\n****************************";
		cout << "\n*** TIC - TAC - TOE GAME ***";
		cout << "\n****************************\n\n";

		for (int j = 0; j < MAX_SIZE; ++j)
		{
			cout << ((j == 0) ? "      " : "   ") << j + 1 << "    ";
		}

		cout << "\n\n";

		for (int i = 0; i < MAX_SIZE; ++i)
		{

			for (int j = 0; j < MAX_SIZE; ++j)
			{
				cout << ((j == 0) ? "      " : "   ") << " " << ((j != MAX_SIZE - 1) ? "   |" : "");
			}

			cout << "\n";

			for (int j = 0; j < MAX_SIZE; ++j)
			{
				cout << ((j == 0) ? (" " + std::to_string(i + 1) + "    ") : "   ") << _board[i][j] << ((j != MAX_SIZE - 1) ? "   |" : "");
			}

			cout << "\n";

			for (int j = 0; j < MAX_SIZE; ++j)
			{
				cout << ((j == 0) ? "      " : "   ") << " " << ((j != MAX_SIZE - 1) ? "   |" : "");
			}

			cout << "\n";

			if (i != MAX_SIZE - 1)
			{
				if (i % 2 == 0)
				{
					for (int j = 0; j < MAX_SIZE; ++j)
					{
						cout << ((j == 0) ? "   -------" : ((j % 2 == 0 && WEAVE_BOARD_DISPLAY) ? "--------" : "|-------"));
					}
				}
				else
				{
					for (int j = 0; j < MAX_SIZE; ++j)
					{
						cout << ((j == 0) ? "   -------" : ((j % 2 == 1 && WEAVE_BOARD_DISPLAY) ? "--------" : "|-------"));
					}
				}
			}

			cout << "\n";
		}
	}

	void TicTacToe::validateCoordinate(int row, int column, char symbol)
	{
		int flag = 0;

		do
		{
			if ((row > MAX_SIZE || row < 1) || (column > MAX_SIZE || column < 1))
			{
				flag = 0;

				cout << "\n Invalid Coordinates!!  Coordinates out of range.";
				cout << "\n Enter coordintes again!";
				cout << "\n Row no. : ";
				cin >> row;
				cout << " Column no. : ";
				cin >> column;
			}
			else if (_board[row - 1][column - 1] == ' ')
			{
				flag = 1;
				_board[row - 1][column - 1] = symbol;
			}
			else
			{
				flag = 0;

				cout << "\n Invalid Coordinates!! Coordinate already occupied by " << _board[row - 1][column - 1];
				cout << "\n Enter coordintes again!";
				cout << "\n Row no. : ";
				cin >> row;
				cout << " Column no. : ";
				cin >> column;
			}
		} while (flag == 0);

	}//End_Of_Validate_coordinate

	int TicTacToe::winCheck(char symbol)
	{
		if (rowCheck(symbol))
			return 1;

		else if (columnCheck(symbol))
			return 2;

		else if (diagonalCheck(symbol))
			return 3;

		else
			return 0;

	}//End_of_Win_Check

	bool TicTacToe::rowCheck(char symbol)
	{
		string symbolToCheck = "";
		string symbolCollectionOnBoard = "";

		for (int j = 0; j < MAX_SIZE; j++)
		{
			symbolToCheck += symbol;
		}

		for (int i = 0; i < MAX_SIZE; i++)
		{
			symbolCollectionOnBoard = "";

			for (int j = 0; j < MAX_SIZE; j++)
			{
				symbolCollectionOnBoard += _board[i][j];
			}

			if (symbolCollectionOnBoard == symbolToCheck)
			{
				return true;
			}
		}

		return  symbolCollectionOnBoard == symbolToCheck;
	}//End_row_check

	bool TicTacToe::columnCheck(char symbol)
	{
		string symbolToCheck = "";
		string symbolCollectionOnBoard = "";

		for (int j = 0; j < MAX_SIZE; j++)
		{
			symbolToCheck += symbol;
		}

		for (int i = 0; i < MAX_SIZE; i++)
		{
			symbolCollectionOnBoard = "";

			for (int j = 0; j < MAX_SIZE; j++)
			{
				symbolCollectionOnBoard += _board[j][i];
			}

			if (symbolCollectionOnBoard == symbolToCheck)
			{
				return true;
			}
		}

		return false;
	}//End_of_column_check

	bool TicTacToe::diagonalCheck(char symbol)
	{
		return leftDiagonalCheck(symbol) || rightDiagonalCheck(symbol);
	}//End_of_diagonal_check

	bool TicTacToe::leftDiagonalCheck(char symbol)
	{
		string symbolToCheck = "";
		string symbolCollectionOnBoard = "";

		for (int j = 0; j < MAX_SIZE; j++)
		{
			symbolToCheck += symbol;
		}

		for (int i = 0; i < MAX_SIZE; i++)
		{
			symbolCollectionOnBoard += _board[i][i];
		}

		return symbolCollectionOnBoard == symbolToCheck;
	}//End_of_left_diagonal_check

	bool TicTacToe::rightDiagonalCheck(char symbol)
	{
		string symbolToCheck = "";
		string symbolCollectionOnBoard = "";

		for (int j = 0; j < MAX_SIZE; j++)
		{
			symbolToCheck += symbol;
		}

		for (int i = 0; i < MAX_SIZE; i++)
		{
			symbolCollectionOnBoard += _board[i][MAX_SIZE - i - 1];
		}

		return symbolCollectionOnBoard == symbolToCheck;
	}//End_of_right_diagonal_check

	void TicTacToe::playGame()
	{
		string player_x, player_o;
		bool over_flag = false;
		int move_counter = 0, row, column;

		bool playAgainFlag = false;
		char playAgain;

		cout << "\n Enter player name for 'X' : ";
		cin >> player_x;
		cout << "\n Enter player name for 'O' : ";
		cin >> player_o;


		do
		{
			while (!over_flag)
			{
				printBoard();

				if (move_counter % 2 == 0)
				{
					cout << "\n " << player_x << "'s chance!!";
					cout << "\n Enter coordinates: ";
					cout << "\n Row no. : ";
					cin >> row;
					cout << " Column no. : ";
					cin >> column;
					validateCoordinate(row, column, 'X');

					printBoard();

					if (move_counter >= 4)
					{
						switch (winCheck('X'))
						{
							case 1: cout << "\n " << player_x << " wins by striking out a row !!\n";
								over_flag = true;
								break;

							case 2: cout << "\n " << player_x << " wins by striking out a column !!\n";
								over_flag = true;
								break;

							case 3: cout << "\n " << player_x << " wins by striking out a diagonal !!\n";
								over_flag = true;
								break;
						}
					}
				}
				else
				{
					cout << "\n " << player_o << "'s chance!!";
					cout << "\n Enter coordinates: ";
					cout << "\n Row no. : ";
					cin >> row;
					cout << " Column no. : ";
					cin >> column;
					validateCoordinate(row, column, 'O');

					printBoard();

					if (move_counter >= 5)
					{
						switch (winCheck('O'))
						{
							case 1: cout << "\n " << player_o << " wins by striking out a row !!\n";
								over_flag = true;
								break;

							case 2: cout << "\n " << player_o << " wins by striking out a column !!\n";
								over_flag = true;
								break;

							case 3: cout << "\n " << player_o << " wins by striking out a diagonal !!\n";
								over_flag = true;
								break;
						}
					}
				}

				move_counter++;

				if (move_counter == MAX_MOVES && !over_flag)
				{
					//check for match draw condition
					over_flag = true;
					cout << "\nMatch Drawn!!\n";
				}
			}

			cout << "\nDo you want to play again (Y for yes)? ";
			cin >> playAgain;

			if (playAgain == 'Y' || playAgain == 'y')
			{
				playAgainFlag = true;
				over_flag = false;
				move_counter = 0;
				clearBoard();
			}
			else
			{
				playAgainFlag = false;
			}

		} while (playAgainFlag);
	}
}