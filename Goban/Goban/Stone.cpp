#include "Stone.h"

Goban::Stone::Stone()
{
	playerID = 0;
	stoneID = 0;
	checked = false;
}

Goban::Stone::Stone(int player)
{
	playerID = player;
	stoneID = 0;
	checked = false;
}

Goban::Stone::Stone(const Stone& stoneToCopy)
{
	playerID = stoneToCopy.getPlayerID();
	stoneID = stoneToCopy.getStoneID();
	checked = false;
}

Goban::Stone::Stone(int player, int stone)
{
	playerID = player;
	stoneID = stone;
	checked = false;
}

Goban::Stone::Stone(int player, int stone, bool check)
{
	playerID = player;
	stoneID = stone;
	checked = check;
}

Goban::Stone::~Stone()
{
}

void Goban::Stone::setPlayerID(int player)
{
	playerID = player;
}

void Goban::Stone::setChecked(bool check)
{
	checked = check;
}

void Goban::Stone::setStoneID(int stone)
{
	stoneID = stone;
}

int Goban::Stone::getPlayerID() const
{
	return playerID;
}

bool Goban::Stone::getChecked() const
{
	return checked;
}

int Goban::Stone::getStoneID() const
{
	return stoneID;
}
