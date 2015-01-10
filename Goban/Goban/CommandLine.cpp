#include <iostream>
#include <string>
#include <iomanip>
#include "Board.h"
#include "Player.h"
#include "Intersection.h"

using namespace Goban;

const int DISPLAY_LINES = 3;

void ClearScreen();
void DrawBoard(Board &);

int main(int argc, char * argv[])
{
	Board theBoard(19);
	Player p1("Lucas", 1);
	Player p2("Computer", 2);
	theBoard.createBoard();
	theBoard.getRows();
	theBoard.getIntersection(0, 0)->setStone(p1.getNewStone());
	theBoard.getIntersection(0, 9)->getRight()->getDown()->setStone(p2.getNewStone());
	theBoard.playStone(&p1, 6, 6);
	theBoard.playStone(&p2, 5, 6);
	theBoard.playStone(&p2, 6, 5);
	theBoard.playStone(&p2, 7, 6);
	theBoard.playStone(&p2, 6, 7);
	ClearScreen();
	DrawBoard(theBoard);
	system("pause");
	return 0;
}


//UGLY BUT WORKS
void DrawBoard(Board &theBoard)
{
	size_t halfDisplayLines = DISPLAY_LINES / 2;
	for (size_t r = 0; r < theBoard.getRows(); r++)
	{
		for (size_t displayLinesRows = 0; displayLinesRows < DISPLAY_LINES; displayLinesRows++)
		{
			for (size_t c = 0; c < theBoard.getColumns(); c++)
			{
				if (halfDisplayLines == displayLinesRows)
				{
					for (size_t displayLinesColumns = 0; displayLinesColumns < DISPLAY_LINES; displayLinesColumns++)
					{
						if (((c == 0 && displayLinesColumns < halfDisplayLines) || (c == theBoard.getColumns() - 1 && displayLinesColumns > halfDisplayLines)))
						{
							std::cout << " ";
						}
						else if (halfDisplayLines == displayLinesColumns)
						{
							if (theBoard.getIntersection(r, c)->hasStone())
							{
								std::cout << theBoard.getIntersection(r, c)->getStone()->getPlayerID();
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
						if ((r == 0 && displayLinesRows < halfDisplayLines) || (r == theBoard.getRows() - 1 && displayLinesRows > halfDisplayLines))
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