#include "InvalidPlayerException.h"


Goban::InvalidPlayerException::InvalidPlayerException() : std::runtime_error("Invalid position selected"), position(-1)
{
}

Goban::InvalidPlayerException::InvalidPlayerException(std::string message) : std::runtime_error(message.c_str()), position(-1)
{
}

Goban::InvalidPlayerException::InvalidPlayerException(int player) : std::runtime_error("Invalid position selected"), position(-1)
{
}

Goban::InvalidPlayerException::InvalidPlayerException(int player, std::string message) : std::runtime_error(message.c_str()), position(-1)
{
}

Goban::InvalidPlayerException::~InvalidPlayerException()
{
}

const char* Goban::InvalidPlayerException::what() const throw()
{
	if (position > -1)
	{
		std::stringstream test;
		test << std::runtime_error::what() << ": with position=" << position;
		return test.str().c_str();
	}
	else
	{
		std::stringstream test;
		test << std::runtime_error::what();
		return test.str().c_str();
	}
}
