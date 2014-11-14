#include "InvalidIntersectionException.h"


Goban::InvalidIntersectionException::InvalidIntersectionException() : std::runtime_error("Invalid position selected"), row(-1), column(-1)
{
}

Goban::InvalidIntersectionException::InvalidIntersectionException(std::string message) : std::runtime_error(message.c_str()), row(-1), column(-1)
{
}

Goban::InvalidIntersectionException::InvalidIntersectionException(int r, int c) : std::runtime_error("Invalid position selected"), row(r), column(c)
{
}

Goban::InvalidIntersectionException::InvalidIntersectionException(int r, int c, std::string message) : std::runtime_error(message.c_str()), row(r), column(c)
{
}

Goban::InvalidIntersectionException::~InvalidIntersectionException()
{
}

const char* Goban::InvalidIntersectionException::what() const throw()
{
	if (row > -1 && column > -1)
	{
		std::stringstream test;
		test << std::runtime_error::what() << ": with row=" << row << " and column=" << column;
		return test.str().c_str();
	}
	else
	{
		std::stringstream test;
		test << std::runtime_error::what();
		return test.str().c_str();
	}
}
