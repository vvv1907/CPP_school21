#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : \
	AForm("Shrubbery Creation", target, _sign, _exec) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : \
	AForm(copy.getName(), copy.getTarget(), copy.getSignGrade(), copy.getExecGrade()) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

int ShrubberyCreationForm::getSCFSign(void) const
{
	return _sign;
}
int ShrubberyCreationForm::getSCFExec(void) const
{
	return _exec;
}

void ShrubberyCreationForm::action(void) const
{
	std::ofstream file(getTarget() + "_shrubbery");
  	if (!file.good())
    	return ;
	std::string	tree = "\n\
                  * *    \n\
               *    *  *\n\
          *  *    *     *  *\n\
         *     *    *  *    *\n\
     * *   *    *    *    *   *\n\
     *     *  *    * * .#  *   *\n\
     *   *     * #.  .# *   *\n\
      *     #.  #: # * *    *\n\
     *   * * #. ##       *\n\
       *       ###\n\
                 ##\n\
                  ##.\n\
                  .##:\n\
                  :###\n\
                  ;###\n\
                 ,####.\n\
    /_________.######._____________/\n\t\t(this is a tree)\n";
	file << tree;
	file.close();
	std::cout << getName() << ": the shrubbery was created in " << getTarget() << std::endl;
}

AForm * ShrubberyCreationForm::clone(const std::string& name)
{
	return new ShrubberyCreationForm(name);
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	(void)assign;
	return (*this);
}

const int ShrubberyCreationForm::_sign = 145;
const int ShrubberyCreationForm::_exec = 137;
