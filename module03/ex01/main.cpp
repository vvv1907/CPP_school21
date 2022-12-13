#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "----------------------------------------------" << std::endl;
	ClapTrap *destructorCheck = new ScavTrap("Checker");
	destructorCheck->attack("Something");
	delete destructorCheck;
	std::cout << "----------------------------------------------" << std::endl;
	
	ClapTrap firstPlayer("Goga");
	ClapTrap secondPlayer("Magoga");
	ScavTrap firstRobot("Goga's son");
	ScavTrap secondRobot("Magoga's son");
	std::cout << "----------------------------------------------" << std::endl;
	
	firstPlayer.getInfo();
	secondPlayer.getInfo();
	firstRobot.getInfo();
	secondRobot.getInfo();
	std::cout << std::endl;

	secondRobot.attack(firstPlayer.getName());
	firstPlayer.takeDamage(secondRobot.getAttackDamage());
	std::cout << std::endl;

	firstPlayer.getInfo();
	secondPlayer.getInfo();
	firstRobot.getInfo();
	secondRobot.getInfo();
	std::cout << std::endl;
	
	firstRobot.guardGate();
	secondRobot.guardGate();
	std::cout << "----------------------------------------------" << std::endl;
	
	return 0;
}
