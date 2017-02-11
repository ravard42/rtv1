# include "rtv1.h"

void	clear_img_dist(t_env *e)
{
	int		i;
	
	i = -1;
	while (++i < MAX_X * MAX_Y)
	{
		*((int *)e->data_img + i) = 0x0;
		e->c->r_dist[i] = MAX_DIST;
	}
}
