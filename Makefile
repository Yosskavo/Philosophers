NAME = philo

SRC = philo.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra  -Werror

all : $(NAME)


$(NAME) : $(OBJ) 
	cc $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean : 
	@rm -fv $(OBJ)

fclean : clean
	@rm -fv $(NAME)

re : fclean all 

.PHONY : clean all re fclean
