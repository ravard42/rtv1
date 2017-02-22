CC = gcc
NAME = rtv1
FLAGS = -Wall -Wextra -Werror -ggdb
SRC = srcs/main.c\
	srcs/parsing/install.c\
	srcs/parsing/analyze.c\
	srcs/parsing/tools.c\
	srcs/parsing/freesplit.c\
	srcs/parsing/set_cam.c\
	srcs/parsing/set_cam_ray_dir.c\
	srcs/parsing/set_sphere.c\
	srcs/parsing/set_plan.c\
	srcs/parsing/set_cylindre.c\
	srcs/parsing/set_cone.c\
	srcs/parsing/set_light.c\
	srcs/matrix_and_vector/mat_operation.c\
	srcs/matrix_and_vector/mat_inversion.c\
	srcs/matrix_and_vector/transfer.c\
	srcs/matrix_and_vector/normal.c\
	srcs/matrix_and_vector/ft_norme.c\
	srcs/matrix_and_vector/vect_manip.c\
	srcs/matrix_and_vector/vect_operation.c\
	srcs/test/sphere_test.c\
	srcs/test/plan_test.c\
	srcs/test/cylindre_test.c\
	srcs/test/cone_test.c\
	srcs/test/global_test.c\
	srcs/light_test/sphere_light_test.c\
	srcs/light_test/plan_light_test.c\
	srcs/light_test/cylindre_light_test.c\
	srcs/light_test/cone_light_test.c\
	srcs/light_test/global_light_test.c\
	srcs/rotation/rot.c\
	srcs/rotation/prevent_rot_cam.c\
	srcs/mlx_stuff/init_env.c\
	srcs/mlx_stuff/key_hook_func.c\
	srcs/mlx_stuff/loop.c\
	srcs/mlx_stuff/hook.c\
	srcs/write_img/print.c\
	srcs/write_img/color.c\
	srcs/write_img/clear.c\

OBJ = $(SRC:.c=.o)

INCL = -I includes/ -I /usr/X11/include
LIB = -L libft/ -lft -L /usr/X11/lib -lXext -lX11 -lmlx
#LIB = -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
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
