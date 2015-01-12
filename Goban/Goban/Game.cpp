#include "Game.h"


Goban::Game::Game(int num, size_t size)
{
	theBoard = new Board(size);
	players = std::vector<Player *>(num);
	deadStoneRemover = nullptr;
}

Goban::Game::Game(int num, size_t c, size_t r)
{
	theBoard = new Board(r, c);
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
	if (deadGroups > 0 && previousPlayer < players.size() && previousPlayer >= 0)
	{
		deadStoneRemover->RemoveDeadStones(players.at(previousPlayer)->getPlayerID(), theBoard);
	}
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


