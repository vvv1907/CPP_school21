#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
private:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	
	~ClapTrap();
	
	ClapTrap &	operator=(const ClapTrap &assign);
	
	std::string	getName() const;
	void		setName(std::string name);
	int			getHitPoints() const;
	void		setHitPoints(int hitPoints);
	int			getEnergyPoints() const;
	void		setEnergyPoints(int energyPoints);
	int			getAttackDamage() const;
	void		setAttackDamage(int attackDamage);

	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		getInfo();
};

#endif
