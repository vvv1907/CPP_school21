#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "\t\t\t *** Simple test ***" << std::endl << std::endl;
	{
		Ice defaultTest;
		AMateria* copyTest = new Ice(defaultTest);
		std::cout << copyTest->getType() << std::endl;
		delete copyTest;
		Ice assignmentTest;
		{
			assignmentTest = defaultTest;
			std::cout << assignmentTest.getType() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "\t\t\t *** Subject test ***" << std::endl << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
    
	AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	std::cout << "##############################################" << std::endl;
	me->use(0, *bob);
    me->use(1, *bob);
	std::cout << "##############################################" << std::endl;
	delete bob;
	delete me;
	delete src;
	std::cout << std::endl;

	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "\t\t\t *** Additional test ***" << std::endl << std::endl;
	ICharacter* first_character = new Character("First");
	ICharacter* noname_character = new Character();
	IMateriaSource* source = new MateriaSource();
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
	AMateria* materia;
	materia = source->createMateria("fire");
	materia = source->createMateria("ice");
    first_character->equip(materia);
	materia = source->createMateria("cure");
    first_character->equip(materia);
	first_character->use(0, *noname_character);
	first_character->use(1, *noname_character);
	first_character->use(2, *noname_character);
	noname_character->unequip(0);
	noname_character->unequip(4);
	noname_character->use(0, *first_character);
	std::cout << std::endl << std::endl;
	delete noname_character;
	std::cout << std::endl;
	delete first_character;
	std::cout << std::endl;
	delete source;
	std::cout << "----------------------------------------------" << std::endl;

	return 0;
}
