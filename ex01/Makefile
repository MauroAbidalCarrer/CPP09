NAME	:= RPN

SRCS	:=	main.cpp\
			RPN.cpp
OBJS	:= $(SRCS:.cpp=.o)

DEPS	=	$(OBJS:.o=.d)

CXX	:= c++
CXXFLAGS := -std=c++98 -Wall -Werror -Wextra -MMD -MP 

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re

-include $(DEPS)