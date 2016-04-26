NAME = ft_ls

HEAD = ft_ls.h

FLAGS = -Wall -Wextra -Werror

SRC = main.c

LIBPATH = -lm -L libft/ -lft

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -o $(NAME) $(SRC) -I $(HEAD) $(LIBPATH)

clean :
	make -C libft/ clean

fclean :
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all
