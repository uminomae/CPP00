#=============================
#flags
#=============================
NAME	:= PhoneBook
CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98
RM		:= rm -f
#=============================
#src
#=============================
SRCS	:= \
main.cpp \
PhoneBook.cpp \

OBJS	= $(SRCS:%.cpp=%.o)

all     : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

s:
	make re
	sh test.sh

.PHONY  : all clean fclean re