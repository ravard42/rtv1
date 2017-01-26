#ifndef	RTV1_H
# define RTV1_H

# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"

# define MAX_X		640
# define MAX_Y		640
# define VP_WIDTH	1.0
# define VP_HEIGHT	1.0
# define VP_DIST	1.0


typedef struct		s_env
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*data_img;
	float		**dir;

}			t_env;


float	**set_dir();
void	print_sphere(float *center, float r, t_env *e, int color);

#endif
