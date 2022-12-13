#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap firstPlayer("Goga"); // create object with fields constructor
	ClapTrap secondPlayer("Magoga");

	std::cout << "----------------------------------------------" << std::endl;
	firstPlayer.getInfo(); // check getInfo-method
	secondPlayer.getInfo();
	std::cout << std::endl;

	if (firstPlayer.getHitPoints() && secondPlayer.getHitPoints())
		firstPlayer.attack(secondPlayer.getName()); // check attack-method
	else
		return 0;
	secondPlayer.takeDamage(firstPlayer.getAttackDamage()); // check takeDamage-method
	std::cout << std::endl;
	
	secondPlayer.setAttackDamage(5); // second player get 5 AttackDamage-level
	if (firstPlayer.getHitPoints() && secondPlayer.getHitPoints())
		secondPlayer.attack(firstPlayer.getName());
	else
		return 0;
	firstPlayer.takeDamage(secondPlayer.getAttackDamage()); // first player lose 5 hits
	std::cout << std::endl;

	firstPlayer.getInfo();
	secondPlayer.getInfo();
	std::cout << std::endl;

	while (firstPlayer.getEnergyPoints() || secondPlayer.getEnergyPoints())
	{
		firstPlayer.beRepaired(2); // player waste EnergyPoints for Repair
		secondPlayer.beRepaired(1);
	}
	std::cout << std::endl;

	firstPlayer.getInfo();
	secondPlayer.getInfo();
	std::cout << std::endl;

	firstPlayer.setAttackDamage(20);
	secondPlayer.setAttackDamage(25);

	if (firstPlayer.getHitPoints() && secondPlayer.getHitPoints())
		firstPlayer.attack(secondPlayer.getName());
	else
		return 0;
	std::cout << std::endl;
	
	secondPlayer.setEnergyPoints(2);
	if (firstPlayer.getHitPoints() && secondPlayer.getHitPoints())
		secondPlayer.attack(firstPlayer.getName());
	else
		return 0;
	firstPlayer.takeDamage(secondPlayer.getAttackDamage());
	std::cout << std::endl;

	firstPlayer.getInfo(); // first player got killed
	secondPlayer.getInfo(); // second player wins
	std::cout << "----------------------------------------------" << std::endl;
	return 0;
}
