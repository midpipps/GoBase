#include "Board.h"

Goban::Board::Board()
{
	rows = 1;
	columns = 1;
	stoneIDCounter = 0;
}

Goban::Board::Board(const size_t boardSize)
{
	rows = boardSize;
	columns = boardSize;
	stoneIDCounter = 0;
}

Goban::Board::Board(const size_t rowSize, const size_t columnSize)
{
	rows = rowSize;
	columns = columnSize;
	stoneIDCounter = 0;
}

Goban::Board::~Board()
{

}

void Goban::Board::setRows(const size_t rowSize)
{
	rows = rowSize;
}

size_t Goban::Board::getRows() const
{
	return rows;
}

void Goban::Board::setColumns(const size_t columnSize)
{
	columns = columnSize;
}

size_t Goban::Board::getColumns() const
{
	return columns;
}

Goban::Intersection *Goban::Board::getIntersection(const size_t r, const size_t c)
{
	if (isValidPosition(r, c))
	{
		return &intersectionMap.at(c).at(r);
	}
	else
	{
		throw InvalidIntersectionException(r, c);
	}
}

void Goban::Board::createBoard()
{
	//setup the array of intersections
	intersectionMap = std::vector<std::vector<Intersection>>(columns, std::vector<Intersection>(rows));
	Intersection::resetIDCounter();
	for (size_t c = 0; c < intersectionMap.size(); c++)
	{
		for (size_t r = 0; r < intersectionMap.at(c).size(); r++)
		{
			intersectionMap.at(c).at(r) = Intersection();
			//if column > 0 then we need to link to the left intersection and link the left intersection to this intersection
			if (c > 0)
			{
				intersectionMap.at(c).at(r).setLeft(&(intersectionMap.at(c - 1).at(r)));
				intersectionMap.at(c - 1).at(r).setRight(&(intersectionMap.at(c).at(r)));
			}

			//if row > 0 then we need to link this intersection with the one above it and the one above it with this one
			if (r > 0)
			{
				intersectionMap.at(c).at(r).setUp(&(intersectionMap.at(c).at(r - 1)));
				intersectionMap.at(c).at(r - 1).setDown(&(intersectionMap.at(c).at(r)));
			}
		}
	}
}


void Goban::Board::playStone(Player *playerToPlay, int r, int c)
{
	if (isValidPosition(r, c))
	{
		getIntersection(r, c)->setStone(playerToPlay->getNewStone());
		getIntersection(r, c)->getStone()->setStoneID(stoneIDCounter++);
	}
	else
	{
		throw InvalidIntersectionException(r, c);
	}
}

bool Goban::Board::isValidPosition(int r, int c)
{
	if (r >= 0 && r < getRows() && c >= 0 && c < getColumns())
	{
		return true;
	}
	return false;
}