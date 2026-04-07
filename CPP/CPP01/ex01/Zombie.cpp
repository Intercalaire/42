
#include "Zombie.hpp"

Zombie::Zombie() : _name("Zombie") {
}

Zombie::Zombie(std::string name) : _name(name) {
}

Zombie::~Zombie() {
	std::cout << _name << " is destroyed" << std::endl;
}

void Zombie::setName(std::string name) {
	_name = name;
}

void Zombie::announce(void) const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
