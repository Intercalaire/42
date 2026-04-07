
#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;

    if (ac != 2)
    {
        std::cout << "Usage: ./Harl_2.0 [level]" << std::endl;
        return 1;
    }
    
    std::string level = av[1];
    harl.complain(av[1]);

    return 0;
}
