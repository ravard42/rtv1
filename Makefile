CC = gcc
NAME = rtv1
FLAGS = -Wall -Wextra -Werror
SRC = srcs/main.c\
	srcs/set_dir.c\
	srcs/print_sphere.c\

OBJ = $(SRC:.c=.o)

INCL = -I includes/ -I /usr/X11/include
LIB = -L libft/ -lft -L /usr/X11/lib -lXext -lX11 -lmlx

all : $(NAME)

$(NAME) : ./libft/libft.a $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(INCL) $(LIB)

./libft/libft.a : 
	make -C libft/

%.o : %.c
	$(CC) -o $@ -c $< $(FLAGS) $(INCL) 

clean : 
	rm -f $(OBJ)
	make -C libft/ fclean

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)
