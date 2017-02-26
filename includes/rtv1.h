#ifndef	RTV1_H
# define RTV1_H

# include <stdio.h>

# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"

# define MAX_X		70
# define MAX_Y		70
# define VP_WIDTH	1.0
# define VP_HEIGHT	1.0
# define VP_DIST	1.0
# define MAX_DIST	500000000
# define PAS		15
# define ROT		M_PI / 6
# define BRI_ANGL	0.2
# define BRI_INT	2

/*
# define EXIT 		65307
# define RECULER 	101
# define AVANCER 	113
# define ROT_D 		100
# define ROT_D2 	65363
# define ROT_G 		97
# define ROT_G2 	65361
# define DEMITOUR	32
# define BAS 		115
# define BAS2 		65364
# define HAUT 		119
# define HAUT2 		65362
*/ 

# define EXIT 53
# define RECULER 14
# define AVANCER 12
# define ROT_D 2
# define ROT_D2 124
# define ROT_G 0
# define ROT_G2 123
# define DEMITOUR 49
# define BAS 1
# define BAS2 125
# define HAUT 13
# define HAUT2 126


typedef struct		s_cam
{
	float		*pos;
	float		**base;
	float		**r_dir;
	float		*r_dist;
	void		**obj;
	char		**name;
}			t_cam;

typedef struct		s_sph
{
	float		*origin;
	float		r;
	int		color;
	float		lum;
	int		bri;
	int		ombre;
	char		id_light;
	struct s_sph	*next;
}			t_sph;

typedef struct		s_pln
{
	float		*origin;
	float		*nor;
	int		color;
	float		lum;
	int		bri;
	int		ombre;
	float		*borne;
	struct s_pln	*next;
}			t_pln;

typedef struct		s_trsf
{
	float		**mat;
	float		*cam_pos;
	float		*obj_pos;
	float		**cam_r_dir;
}
			t_trsf;
typedef struct		s_cyl
{
	float		*origin;
	float		*axe;
	float		r;
	int		color;
	float		lum;
	int		bri;
	int		ombre;
	float		*borne;
	char		id_light;
	t_trsf		*t;
	struct s_cyl	*next;
}			t_cyl;

typedef struct		s_con
{
	float		*origin;
	float		*axe;
	int		color;
	float		lum;
	int		bri;
	int		ombre;
	float		*borne;
	t_trsf		*t;
	struct s_con	*next;
}			t_con;

typedef struct		s_obj
{
	t_sph		*s;	
	t_pln		*p;
	t_cyl		*cy;
	t_con		*co;
}			t_obj;

typedef struct		s_lght
{
	char		*name;
	float		*origin;
	int		color;
	int		id;
	int		scope;
	struct s_lght	*next;
}			t_lght;

typedef struct		s_env
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*data_img;
	t_cam		*c;
	t_obj		*o;
	t_lght		*l;
}			t_env;

t_env	*install(char *path);
int	analyzer(char **tmp);
void	not_a_valid_file(char *str);
void	free_split(char **tmp);
void	free_double_split(char ***input);
int	input_number(char **tmp);
int	ft_atoi_hexa(char *s);
int	ft_is_float(char *tmp);
float	ft_atof(char *s);
float	*load_vect(float *a, char *s);
void	set_cam(char **tmp, t_env *e);
void	set_cam_base(t_cam *c);
void	set_cam_ray_dir(t_cam *c);
void	set_sphere(char **tmp, t_obj *o);
void	set_plan(char **tmp, t_obj *o);
void	set_cylindre(char **tmp, t_obj *o);
void	set_cone(char **tmp, t_obj *o);
void	set_light(char **tmp, t_env *e);

float	*matrix_product(float *mp, float **mat, float *src);
float 	**inverse(float **mat);
void	construct_transfer_mat(float **base);
void	set_cyl_transfer(t_cyl *cy);
void	set_cone_transfer(t_con *co);
float	*set_vect(float *dst, float a, float b, float c);
float	*vectorial_copy(float *dst, float *src);
float	*vectorial_sum(float *sum, float *u, float *v);
float	*vectorial_multi(float *multi, float k, float *u);
float	*vectorial_subtraction(float *sub, float *u, float *v);
float	scalar_product(float *u, float *v);
float	*vectorial_product(float *prod, float *u, float *v);
float	ft_dist(float *a, float *b);
void	ft_norme(float *v);
void	sph_normal(float *nor, float *p, t_sph *s);
void	cyl_normal(float *nor, float *p, t_cyl *cy);
void	con_normal(float *nor, float *p, t_con *co);

int	sphere_test(t_env *e);
int	plan_test(t_env *e);
int	cylindre_test(t_env *e);
int	cone_test(t_env *e);
void	global_test(t_env *e);

int	sphere_light_test(float *p, void *obj, t_sph *s, t_lght *l);
int	plan_light_test(float *p, void *obj, t_pln *pl, t_lght *l);
int	cylindre_light_test(float *p, void *obj, t_cyl *cy, t_lght *l);
int	cone_light_test(float *p, void *obj, t_con *co, t_lght *l);
void	global_light_test(float *p, void *obj, t_env *e);

void	rot(float *eZ, float value, float *n);
int	prevent_hori_rot(int keycode, float **base);
int	prevent_vert_rot(int keycode, t_env *e);

void	init_env(t_env *e);
void	loop(t_env *e);
int	expose_hook(t_env *e);
int	key_hook(int keycode, t_env *e);
void	rot_d(int keycode, t_env *e);
void	rot_g(int keycode, t_env *e);
void	demi_tour(t_env *e);
void	rot_b(int keycode, t_env *e);
void	rot_h(int keycode, t_env *e);

float	*hexa_to_rgb(float *rgb, int *hexa);
int	*rgb_to_hexa(int *hexa, float *rgb);
float	*rgb_to_coef(float *rgb);
float	*coef_to_rgb(float *coef);
float	*luminosity(float *rgb, char *name, t_obj *o);
void	print(t_env *e);
void	clear_img_dist_obj(t_env *e);

void	free_cam(t_env *e);
int	free_light(t_env *e);
int	free_sphere(t_obj *o);
int	free_all_plan(t_obj *o);
int	free_all_cylindre(t_obj *o);
int	free_all_cone(t_obj *o);

int	ft_exit(t_env *e);

#endif
