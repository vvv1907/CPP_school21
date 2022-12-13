NAME = AnimalSound

DIR = ./
FILES = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

SRCS = $(addprefix $(DIR), $(FILES))
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

HEADER = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp

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
