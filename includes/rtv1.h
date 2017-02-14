#ifndef	RTV1_H
# define RTV1_H

# include <stdio.h>

# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"
# include <stdio.h>

# define MAX_X		400
# define MAX_Y		400
# define VP_WIDTH	1.0
# define VP_HEIGHT	1.0
# define VP_DIST	1.0
# define MAX_DIST	50000000

# define EXIT 		65307
# define RECULER 	101
# define AVANCER 	113
# define ROT_D 		100
# define ROT_D2 	65363
# define ROT_G 		97
# define ROT_G2 	65361
# define BAS 		115
# define BAS2 		65364
# define HAUT 		119
# define HAUT2 		65362
 
/*
# define EXIT 53
# define RECULER 14
# define AVANCER 12
# define ROT_D 2
# define ROT_D2 124
# define ROT_G 0
# define ROT_G2 123
# define BAS 13
# define BAS2 126
# define HAUT 1
# define HAUT2 125
*/

typedef struct		s_cam
{
	float		*pos;
	float		**base;
	float		**r_dir;
	float		*r_dist;
}			t_cam;

typedef struct		s_sph
{
	float		*origin;
	float		r;
	int		color;
	struct s_sph	*next;
}			t_sph;

typedef struct		s_pln
{
	float		*origin;
	float		*nor;
	int		color;
	struct s_pln	*next;
}			t_pln;

typedef struct		s_cyl
{
	float		*origin;
	float		r;
	int		val;
	float		*rot;
	int		color;
	float		*borne;
	struct s_cyl	*next;
}			t_cyl;

typedef struct		s_con
{
	float		*origin;
	int		val;
	float		*rot;
	int		color;
	float		*borne;
	struct s_con	*next;
}			t_con;

typedef struct		s_obj
{
	t_sph		*s;	
	t_pln		*p;
	t_cyl		*cy;
	t_con		*co;
}			t_obj;

typedef struct		s_trsf
{
	float		**mat;
	float		*cam_pos;
	float		*obj_pos;
	float		**cam_r_dir;
}			t_trsf;


typedef struct		s_env
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*data_img;
	t_cam		*c;
	t_obj		*o;
	t_trsf		*t;
}			t_env;



void		not_a_valid_file();

t_env	*install(char *path);
void	init_env(t_env *e);
int	ft_atoi_hexa(char *s);
int	ft_is_int(char *tmp);
void	free_split(char **tmp);
void	load_vect(char *s, float *a);
int	analyzer(char *tmp);
void	not_a_valid_file();

void	set_cam_base(t_cam *c);
void	set_cam_ray_dir(t_cam *c);
void	set_cam(char **tmp, t_cam *c);

void	set_sphere(char **tmp, t_obj *o);
void	set_plan(char **tmp, t_obj *o);
void	set_cylindre(char **tmp, t_obj *o);
void	set_cone(char **tmp, t_obj *o);

void	loop(t_env *e);
int	expose_hook(t_env *e);
int	key_hook(int keycode, t_env *e);


float	*matrix_product(float *mp, float **mat, float *src);
float	*vectorial_sum(float *sum, float *u, float *v);
float	*vectorial_multi(float *u, int k);
float	*vectorial_subtraction(float *sub, float *u, float *v);
float	*vectorial_product(float *prod, float *u, float *v);
void	ft_norme(float *v);
void	rot_d(float *eZcam);
void	rot_g(float *eZcam);
void	rot_b(float **base);
void	rot_h(float **base);
void	print_all(t_env *e);
void	print_sphere(t_env *e);
void	print_plan(t_env *e);


float 	**inverse(float **mat);

void	init_transfer_stuff(t_env *e);
void	rot(float *eZ, float value, float *n);
void	construct_transfer_mat(float **base);
void	set_transfer_stuff(float rot_val, float *axe_rot, float *obj_pos, t_env *e);


void	print_cylindre(t_env *e);
void	print_cone(t_env *e);
void	clear_img_dist(t_env *e);

#endif
