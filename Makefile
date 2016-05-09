NAME = ft_ls

HEAD = ft_ls.h

FLAGS = -Wall -Wextra -Werror

SRC = main.c	\
	  date.c	\
	  flags.c	\
	  init.c	\
	  print.c	\
	  rights.c

LIBPATH = -lm -L libft/ -lft

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -I $(HEAD) ./libft/libft.a

clean :

fclean :
	rm -f $(NAME)

re : fclean all
