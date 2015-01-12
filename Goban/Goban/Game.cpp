#include "Game.h"


Goban::Game::Game(int num, size_t size)
{
	theBoard = new Board(size);
	theBoard->createBoard();
	players = std::vector<Player *>(num);
	deadStoneRemover = nullptr;
}

Goban::Game::Game(int num, size_t r, size_t c)
{
	theBoard = new Board(r, c);
	theBoard->createBoard();
	players = std::vector<Player *>(num);
	deadStoneRemover = nullptr;
}

Goban::Game::~Game()
{
	delete theBoard;
	for (int i = 0; i < players.size(); i++)
	{
		delete players.at(i);
	}
}

void Goban::Game::setPlayer(const int pNum, const Goban::Player & p)
{
	setPlayer(pNum, p.getPlayerName(), p.getPlayerID());
}

void Goban::Game::setPlayer(const int pNum, const std::string name)
{
	setPlayer(pNum, name, pNum);
}

void Goban::Game::setPlayer(const int pNum, const std::string name, const int playerID)
{
	if (pNum < players.size() && pNum >= 0)
	{
		players[pNum] = new Player(name, playerID);
	}
	else
	{
		throw InvalidPlayerException(pNum);
	}
}

Goban::Player * Goban::Game::getPlayer(int pNum) const
{
	if (pNum < players.size() && pNum >= 0)
	{
		return players.at(pNum);
	}
	else
	{
		throw InvalidPlayerException(pNum);
	}
}

void Goban::Game::setDeadStoneRemover(IRemoveDeadStones * theRemover)
{
	deadStoneRemover = theRemover;
}

Goban::IRemoveDeadStones::deadStoneReturn Goban::Game::runDeadStoneRemover()
{
	int deadGroups = deadStoneRemover->AnalyzeBoard(theBoard);
	IRemoveDeadStones::deadStoneReturn returnStones;
	if (deadGroups > 0 && previousPlayer < players.size() && previousPlayer >= 0)
	{
		returnStones = deadStoneRemover->RemoveDeadStones(players.at(previousPlayer)->getPlayerID(), theBoard);
	}
	return returnStones;
}

void Goban::Game::makeMove(int pNum, int r, int c)
{
	if (pNum < players.size() && pNum >= 0)
	{
		previousPlayer = pNum;
		theBoard->playStone(players.at(pNum), r, c);
	}
	else
	{
		throw InvalidPlayerException(pNum);
	}
}

const Goban::Stone * Goban::Game::getStone(int r, int c)
{
	if (theBoard->getIntersection(r, c)->hasStone())
	{
		return theBoard->getIntersection(r, c)->getStone();
	}
	else
	{
		return nullptr;
	}
}


