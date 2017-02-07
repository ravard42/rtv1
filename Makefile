CC = gcc
NAME = rtv1
FLAGS = -Wall -Wextra -Werror -ggdb
SRC = srcs/main.c\
	srcs/init_env.c\
	srcs/loop.c\
	srcs/hook.c\
	srcs/ft_norme.c\
	srcs/rot_cam.c\
	srcs/set_base.c\
	srcs/matrix_operation.c\
	srcs/set_dir.c\
	srcs/print.c\
	srcs/print_sphere.c\
	srcs/print_plan.c\
	srcs/clear.c\

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
