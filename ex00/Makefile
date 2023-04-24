#=============================
#flags
#=============================
NAME	:= megaphone
CXX     := clang++
CXXFLAGS:= -Wall -Wextra -Werror
RM		:= rm -f
#=============================
#src
#=============================
SRCS	:= \
megaphone.cpp

OBJS	= $(SRCS:%.cpp=%.o)

all     : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY  : all clean fclean re