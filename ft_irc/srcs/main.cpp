
#include "Server.hpp"
#include "error.hpp"
#include "ft_irc.hpp"
#include <csignal>

errno_irc_code errno_irc = NO_ERROR;
bool stopServer = false;

void signalHandler(int signal) {
    if (signal == SIGINT){
		std::cout << std::endl;
		stopServer = true;
	}
}

int main(int argc, char *argv[])
{
    uint16_t	port;
	std::string	password;

	std::signal(SIGINT, signalHandler);
	std::signal(SIGPIPE, SIG_IGN);
	try {
		argValid(argc);
		port = portValid(argv[1]);
		password = passwordValid(argv[2]);
		Server server(port, password);
		
		if (!server.initialize())
			return 1;

		server.run();
	}
	catch (const std::exception& e)
	{
		if (!stopServer)
			std::cerr << RED << e.what() << WHITE << std::endl;
	}
	return 0;
}
