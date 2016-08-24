NAME = ft_ls

PATH1 = ./src/

HEAD = -I./include

FLAGS = -Wall -Wextra -Werror

FILE = main.c	\
	  date.c	\
	  flags.c	\
	  init.c	\
	  print.c	\
	  rights.c	\
	  dir.c		\
	  lst.c		\
	  bonus.c	\
	  ls.c

SRC = $(FILE:%c=$(PATH1)%c)

LIBPATH = -lm -L libft/ -lft

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAGS) -o $(NAME) $(SRC) $(HEAD) -I./libft/include ./libft/libft.a

clean :
	rm -f $(OBJ)
	make -C libft/ clean

fclean :
	make -C libft/ fclean
	rm -f $(NAME) $(OBJ)

re : fclean all
