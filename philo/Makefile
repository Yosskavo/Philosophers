NAME = philo

SRC = philo.c parcing.c ft_start.c ft_lst.c ft_life.c ft_routine.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra  -Werror -pthread

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
