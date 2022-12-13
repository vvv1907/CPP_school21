#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "----------------------------------------------" << std::endl;
	ClapTrap *destructorCheck = new FragTrap("Checker");
	destructorCheck->attack("Something");
	delete destructorCheck;
	std::cout << "----------------------------------------------" << std::endl;
	ClapTrap firstPlayer("Goga");
	ClapTrap secondPlayer("Magoga");
	ScavTrap firstRobot("Goga's son");
	FragTrap secondRobot("Magoga's son");
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << std::endl;
	
	firstPlayer.getInfo();
	secondPlayer.getInfo();
	firstRobot.getInfo();
	secondRobot.getInfo();
	std::cout << std::endl;
	
	secondRobot.attack(firstPlayer.getName());
	firstPlayer.takeDamage(secondRobot.getAttackDamage());
	std::cout << std::endl;

	firstRobot.attack(secondPlayer.getName());
	secondPlayer.takeDamage(firstRobot.getAttackDamage());
	std::cout << std::endl;

	firstPlayer.getInfo();
	secondPlayer.getInfo();
	firstRobot.getInfo();
	secondRobot.getInfo();
	std::cout << std::endl;

	firstRobot.guardGate();
	secondRobot.highFivesGuys();
	std::cout << "----------------------------------------------" << std::endl;
	
	return 0;
}
