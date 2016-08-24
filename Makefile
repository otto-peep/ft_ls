NAME = ft_ls

PATH1 = ./src/

HEAD = -I ./include

FLAGS = -Wall -Wextra -Werror

FILE = main.c	\
	  date.c	\
	  flags.c	\
	  init.c	\
	  print.c	\
	  rights.c	\
	  dir.c		\
	  lst.c		\
	  bonus.c

SRC = $(FILE:%c=$(PATH1)%c)

LIBPATH = -lm -L libft/ -lft

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -lm -L libft/ -lft -o $(NAME) $(SRC) $(HEAD)   -I libft

clean :

fclean :
	rm -f $(NAME)

re : fclean all
