#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap firstPlayer("Goga");
	std::cout << std::endl;
	firstPlayer.whoAmI();
	std::cout << std::endl;
	DiamondTrap secondPlayer("Magoga");
	std::cout << std::endl;
	secondPlayer.whoAmI();
	std::cout << "----------------------------------------------" << std::endl;
	
	firstPlayer.getInfo();
	secondPlayer.getInfo();
	std::cout << std::endl;

	secondPlayer.attack(firstPlayer.getName());
	firstPlayer.takeDamage(secondPlayer.getAttackDamage());
	std::cout << std::endl;

	firstPlayer.getInfo();
	secondPlayer.getInfo();
	std::cout << std::endl;

	firstPlayer.guardGate();
	secondPlayer.guardGate();
	std::cout << std::endl;

	firstPlayer.highFivesGuys();
	secondPlayer.highFivesGuys();
	std::cout << "----------------------------------------------" << std::endl;

	return 0;
}
