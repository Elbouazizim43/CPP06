NAME = convert

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS =  main.cpp ScalarConverter.cpp 
OBJS = $(SRCS:.cpp=.o)
HEADERS = ScalarConverter.hpp
all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all