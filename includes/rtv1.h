#ifndef	RTV1_H
# define RTV1_H

# include <stdio.h>

# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"
# include <stdio.h>

# define MAX_X		640
# define MAX_Y		640
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
}			t_pln;

typedef struct		s_cyl
{
}			t_cyl;

typedef struct		s_con
{
}			t_con;

typedef struct		s_obj
{
	t_sph		*s;	
	t_pln		*p;
	t_cyl		*cy;
	t_con		*co;
}			t_obj;



typedef struct		s_env
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*data_img;
	t_cam		*c;
	t_obj		*o;
}			t_env;

void		not_a_valid_file();

t_env	*install(char *path);
void	init_env(t_env *e);
int	ft_atoi_hexa(char *s);
void	load_vect(char *s, float *a);
int	analyzer(char *tmp);
int	analyzer_cam(char **tmp);
int	analyzer_sphere(char **tmp);

void	set_cam_base(t_cam *c);
void	set_cam_ray_dir(t_cam *c);
void	set_cam(char **tmp, t_cam *c);

void	set_sphere(char **tmp, t_obj *o);

void	loop(t_env *e);
int	expose_hook(t_env *e);
int	key_hook(int keycode, t_env *e);


float	*matrix_product(float **mat, float *src, float *mp);
float	*vectorial_sum(float *u, float *v, float *sum);
float	*vectorial_multi(int i, float *u);
float	*vectorial_subtraction(float *u, float *v, float *sub);
float	*vectorial_product(float *u, float *v, float *prod);
void	ft_norme(float *v);
void	rot_d(float *eZcam);
void	rot_g(float *eZcam);
void	rot_b(float **base);
void	rot_h(float **base);
void	print_all(t_env *e);
void	print_sphere(float *center, float r, t_env *e, int color);
void	print_plan(float *c, float *n, t_env *e, int color);
void	rot(float *n, float value, float *eZ);
void	construct_transfer_mat(float **base);
float 	**inverse(float **mat);
void	print_cyl(float *origin, float r, float *n, float value, t_env *e, int color);
void	print_cone(float *origin, float *a, float *n, float value, t_env *e, int color);
void	clear_img_dist(t_env *e);

#endif
