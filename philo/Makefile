NAME = philo

SRC = philo.c ft_eat.c ft_time.c parcing.c	ft_strlen.c ft_start.c ft_lst.c ft_life.c ft_routine.c ft_monitoring.c ft_usleep.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra  -Werror -pthread -g 

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
