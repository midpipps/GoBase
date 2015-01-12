#include "Player.h"


Goban::Player::Player()
{
	playerName = "";
	playerID = 0;
}

Goban::Player::Player(std::string name)
{
	playerName = name;
	playerID = 0;
}

Goban::Player::Player(std::string name, int playersID)
{
	playerID = playersID;
	playerName = name;
}

Goban::Player::~Player()
{
	for (size_t i = 0; i < playersStones.size(); i++)
	{
		delete playersStones.at(i);
		playersStones.at(i) = nullptr;
	}
}

Goban::Stone * Goban::Player::getNewStone()
{
	playersStones.push_back(new Stone(playerID));
	return playersStones.at(playersStones.size() - 1);
}

int Goban::Player::getCapturedStoneCount() const
{
	size_t capturedStones = 0;
	for (size_t i = 0; i < playersStones.size(); i++)
	{
		if (playersStones.at(i)->getIsDead())
		{
			capturedStones += 1;
		}
	}
	return capturedStones;
}

void Goban::Player::setPlayerName(std::string newName)
{
	playerName = newName;
}

std::string Goban::Player::getPlayerName() const
{
	return playerName;
}

void Goban::Player::setPlayerID(int newID)
{
	playerID = newID;
}

int Goban::Player::getPlayerID() const
{
	return playerID;
}