NAME = Bureaucrat

DIR = ./
FILES = main.cpp Bureaucrat.cpp AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp

SRCS = $(addprefix $(DIR), $(FILES))
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

HEADER = Bureaucrat.hpp AForm.hpp \
		ShrubberyCreationForm.hpp \
		RobotomyRequestForm.hpp \
		PresidentialPardonForm.hpp \
		Intern.hpp

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $@

%.o: %.cpp $(HEADER) Makefile
	$(CPP) $(CPPFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(OBJS) *_shrubbery

fclean: clean
	$(RM) $(NAME)

re: fclean all
