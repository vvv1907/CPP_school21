#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
private:
	std::string _ideas[100];
public:
	Brain();
	Brain(std::string idea);
	Brain(const Brain &copy);

	virtual		~Brain();

	Brain & 	operator=(const Brain &assign);

	std::string	getIdea(int number) const;
	void 		setIdea(int number, std::string idea);
};

#endif
