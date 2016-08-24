NAME = ft_ls

PATH1 = ./src/

HEAD = -I ./include

FLAGS = -Wall -Wextra -Werror --std=c99

FILE = main.c	\
	  date.c	\
	  flags.c	\
	  init.c	\
	  print.c	\
	  rights.c	\
	  tools.c	\
	  dir.c		\
	  lst.c

SRC = $(FILE:%c=$(PATH1)%c)

LIBPATH = -lm -L libft/ -lft

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME):
	gcc -lm -L libft/ -lft -o $(NAME) $(SRC) $(HEAD)   -I libft

clean :

fclean :
	rm -f $(NAME)

re : fclean all
