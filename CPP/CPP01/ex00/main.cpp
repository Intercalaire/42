
#include "Zombie.hpp"

int main()
{
	Zombie zombie_toto("Toto");
	Zombie zombie_test("Test");
	Zombie zombie_trump("Trump");

	zombie_toto.announce();
	zombie_test.announce();
	zombie_trump.announce();
	randomChump("Random");

	Zombie *zombie_solo;

	zombie_solo = newZombie("Solo");
	zombie_solo->announce();
	delete (zombie_solo);

	return (0);
}
