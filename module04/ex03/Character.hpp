#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria*	_inventory[ISIZE];
public:
	Character();
	Character(std::string name);
	Character(const Character &copy);

	virtual 	~Character();

	Character &	operator=(const Character &assign);

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif
