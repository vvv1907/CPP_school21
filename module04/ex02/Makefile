NAME = AbstractAnimal

DIR = ./
FILES = main.cpp AAnimal.cpp Cat.cpp Dog.cpp Brain.cpp

SRCS = $(addprefix $(DIR), $(FILES))
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

HEADER = AAnimal.hpp Cat.hpp Dog.hpp Brain.hpp

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
