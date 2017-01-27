# include "rtv1.h"

void	print_plan(float *c, float *n, t_env *e, int color)
{
	int	i;
	float	tmp[2];
	
	i = -1;
	while (++i < MAX_X * MAX_Y)
	{
		tmp[0] = e->dist[i];
		tmp[1] = (n[0] * c[0] + n[1] * c[1] + n[2] * c[2]) / (n[0] * e->dir[i][0] + n[1] * e->dir[i][1] + n[2] * e->dir[i][2]);
		e->dist[i] = (tmp[1] > 0 && tmp[1] < e->dist[i]) ? tmp[1] : e->dist[i];
		if (tmp[0] != e->dist[i])
				*((int *)e->data_img + i) = color;


	}
}
