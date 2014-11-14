#include "intersection.h"
unsigned int Goban::Intersection::iDTracker = 0;

Goban::Intersection::Intersection()
{
	left = nullptr;
	right = nullptr;
	up = nullptr;
	down = nullptr;
	stone = nullptr;
	id = iDTracker++;
}

Goban::Intersection::Intersection(Intersection *pleft)
{
	left = pleft;
	right = nullptr;
	up = nullptr;
	down = nullptr;
	stone = nullptr;
	id = iDTracker++;
}

Goban::Intersection::Intersection(Intersection *pleft, Intersection *pright)
{
	left = pleft;
	right = pright;
	up = nullptr;
	down = nullptr;
	stone = nullptr;
	id = iDTracker++;
}

Goban::Intersection::Intersection(Intersection *pleft, Intersection *pright, Intersection *pup)
{
	left = pleft;
	right = pright;
	up = pup;
	down = nullptr;
	stone = nullptr;
	id = iDTracker++;
}

Goban::Intersection::Intersection(Intersection *pleft, Intersection *pright, Intersection *pup, Intersection *pdown)
{
	left = pleft;
	right = pright;
	up = pup;
	down = pdown;
	stone = nullptr;
	id = iDTracker++;
}

Goban::Intersection::~Intersection()
{
}

Goban::Intersection* Goban::Intersection::getUp()
{
	return up;
}

void Goban::Intersection::setUp(Intersection *inter)
{
	up = inter;
}

Goban::Intersection* Goban::Intersection::getDown()
{
	return down;
}

void Goban::Intersection::setDown(Intersection *inter)
{
	down = inter;
}

Goban::Intersection* Goban::Intersection::getRight()
{
	return right;
}

void Goban::Intersection::setRight(Intersection *inter)
{
	right = inter;
}

Goban::Intersection* Goban::Intersection::getLeft()
{
	return left;
}

void Goban::Intersection::setLeft(Intersection *inter)
{
	left = inter;
}

unsigned int Goban::Intersection::getID() const
{
	return id;
}

void Goban::Intersection::resetIDCounter()
{
	iDTracker = 0;
}

void Goban::Intersection::setStone(Stone *pstone)
{
	stone = pstone;
}

Goban::Stone * Goban::Intersection::getStone()
{
	return stone;
}

bool Goban::Intersection::hasStone() const
{
	return (stone != nullptr);
}