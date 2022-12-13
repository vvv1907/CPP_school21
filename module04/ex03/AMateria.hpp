#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# define ISIZE 4
# define SSIZE 4

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string	_type;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria &copy);

	virtual 	~AMateria();

	AMateria &	operator=(const AMateria &assign);

	std::string const & getType() const; //Returns the materia type
	
	virtual AMateria * clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
