NAME = FragTrap

DIR = ./
FILES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

SRCS = $(addprefix $(DIR), $(FILES))
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

HEADER = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

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
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
