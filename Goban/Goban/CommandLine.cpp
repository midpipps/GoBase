#include <iostream>
#include <string>
#include <iomanip>
#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "Intersection.h"

using namespace Goban;

const int DISPLAY_LINES = 3;
const int ROWS = 19;
const int COLUMNS = 19;

void ClearScreen();
void DrawBoard(Game &);

int main(int argc, char * argv[])
{
	Game theGame(2, 19, 19);
	theGame.setPlayer(0, "Player1", 1);
	theGame.setPlayer(1, "Player2", 2);
	theGame.makeMove(0, 0, 0);
	theGame.makeMove(1, 0, 9);
	theGame.makeMove(0, 6, 6);
	theGame.makeMove(1, 5, 6);
	theGame.makeMove(1, 6, 5);
	theGame.makeMove(1, 7, 6);
	theGame.makeMove(1, 6, 7);
	ClearScreen();
	DrawBoard(theGame);
	system("pause");
	return 0;
}


//UGLY BUT WORKS
void DrawBoard(Game &theGame)
{
	size_t halfDisplayLines = DISPLAY_LINES / 2;
	for (size_t r = 0; r < ROWS; r++)
	{
		for (size_t displayLinesRows = 0; displayLinesRows < DISPLAY_LINES; displayLinesRows++)
		{
			for (size_t c = 0; c < COLUMNS; c++)
			{
				if (halfDisplayLines == displayLinesRows)
				{
					for (size_t displayLinesColumns = 0; displayLinesColumns < DISPLAY_LINES; displayLinesColumns++)
					{
						if (((c == 0 && displayLinesColumns < halfDisplayLines) || (c == COLUMNS - 1 && displayLinesColumns > halfDisplayLines)))
						{
							std::cout << " ";
						}
						else if (halfDisplayLines == displayLinesColumns)
						{
							if (theGame.getStone(r, c) != nullptr)
							{
								std::cout << theGame.getStone(r, c)->getPlayerID();
							}
							else
							{
								std::cout << " ";
							}
						}
						else
						{
							std::cout << "-";
						}
					}
				}
				else
				{
					for (size_t displayLinesColumns = 0; displayLinesColumns < DISPLAY_LINES; displayLinesColumns++)
					{
						if ((r == 0 && displayLinesRows < halfDisplayLines) || (r == ROWS - 1 && displayLinesRows > halfDisplayLines))
						{
							std::cout << " ";
						}
						else if (halfDisplayLines == displayLinesColumns)
						{
							std::cout << "|";
						}
						else
						{
							std::cout << " ";
						}
					}
				}
			}
			std::cout << std::endl;
		}
	}
}

void ClearScreen()
{
	system("cls");
}