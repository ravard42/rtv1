#ifndef	RTV1_H
# define RTV1_H

# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"

# define MAX_X				640
# define MAX_Y				640
# define VP_WIDTH			1.0
# define VP_HEIGHT			1.0
# define VP_DIST			1.0
# define MAX_DIST_PERCEPTION		50000

# define EXIT 65307
 
/*
# define EXIT 53
*/

typedef struct		s_env
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*data_img;
	float		**dir;
	float		*dist;

}			t_env;


void	expose(t_env *e);
int	expose_hook(t_env *e);
int	key_hook(int keycode, t_env *e);
void	set_dir_dist(t_env *e);
void	print_sphere(float *center, float r, t_env *e, int color);
void	print_plan(float *c, float *n, t_env *e, int color);

#endif
