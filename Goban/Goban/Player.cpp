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
	for (int i = 0; i < playersStones.size(); i++)
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

void Goban::Player::addCapturedStone(Stone * thestone)
{
	capturedStones.push_back(thestone);
}

int Goban::Player::getCapturedStoneCount() const
{
	return capturedStones.size();
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