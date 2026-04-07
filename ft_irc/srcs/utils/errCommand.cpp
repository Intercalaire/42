
#include "error.hpp"
#include <sys/socket.h>

bool	errCommand(bool condition, int client_fd, const std::string& err)
{
	if (condition)
	{
		send(client_fd, err.c_str(), err.size(), 0);
		return (true);
	}
	return (false);
}
