NAME= philo_bonus

FLAGS = 

HEADER= philo_bonus.h

FILES= main_bonus.c utils_bonus.c routine_bonus.c init_bonus.c monitor_bonus.c

OBJS= $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cc $(OBJS) -o $(NAME)

%.o:%.c $(HEADER)
	cc -c $< -o $@

clean:
	rm -fr *.o

fclean: clean
	rm -fr $(NAME)