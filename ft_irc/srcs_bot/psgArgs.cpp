
#include "error.hpp"
#include "bot.hpp"
#include "stdint.h"

uint16_t	portValid(const char *strPort)
{
	uint16_t	port;

	port = ft_atous(strPort);
	if (errno_irc || port <= 1024)
		throw errPsg::invalidPortException();
	return (port);
}

std::string	passwordValid(const char *password)
{
    std::string pwStr(password);

    if (pwStr.empty())
		throw errPsg::invalidPasswordException();
	return (pwStr);
}

void	argValid(int argc)
{
	if (argc != 3)
		throw errPsg::invalidArgException();
}
