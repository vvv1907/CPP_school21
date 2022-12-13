#ifndef	SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	static const int	_sign;
	static const int	_exec;
	
	ShrubberyCreationForm();

	ShrubberyCreationForm & operator=(const ShrubberyCreationForm &assign);

public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);

	~ShrubberyCreationForm();

	int		getSCFSign(void) const;
	int		getSCFExec(void) const;
	
	void	action(void) const;
	static AForm * clone(const std::string &name);
};

#endif
