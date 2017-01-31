# include "rtv1.h"

void	print_sphere(float *c, float r, t_env *e, int color)
{
	int	i;
	float	param[3];
	float	delt;
	float	tmp;
	float	sol[3];

	

	i = -1;
	while (++i < MAX_X * MAX_Y)
	{
		tmp = e->s->dist[i];
		param[0] = pow(e->s->dir[i][0], 2) + pow(e->s->dir[i][1], 2) + pow(e->s->dir[i][2], 2);
		param[1] = 2 * (e->s->dir[i][0] * (e->s->cam[0] - c[0]) + e->s->dir[i][1] * (e->s->cam[1] - c[1]) + e->s->dir[i][2] * (e->s->cam[2] - c[2]));
		param[2] = pow(e->s->cam[0] - c[0], 2) + pow(e->s->cam[1] - c[1], 2) + pow(e->s->cam[2] - c[2], 2) - pow(r, 2);
		if ((delt = pow(param[1], 2) - 4 * param[0] * param[2]) == 0)
		{
			sol[0] = -param[1] / (2 * param[0]);
			e->s->dist[i] = (sol[0] > VP_DIST  && e->s->dist[i] > sol[0]) ? sol[0] : e->s->dist[i];
		}
		else if (delt > 0)
		{
			sol[0] = (-param[1] + sqrt(delt))/ (2 * param[0]);
			sol[1] = (-param[1] - sqrt(delt))/ (2 * param[0]);
			if ((sol[0] <= VP_DIST && sol[1] > VP_DIST) || (sol[0] > VP_DIST && sol[1] <= VP_DIST))
			{
				sol[2] = (sol[0] > VP_DIST) ? sol[0] : sol[1];
				e->s->dist[i] = (e->s->dist[i] > sol[2]) ? sol[2] : e->s->dist[i];
			}
			else if (sol[0] > VP_DIST && sol[1] > VP_DIST)	
			{
				sol[2] = (sol[0] <= sol[1]) ? sol[0] : sol[1];
				e->s->dist[i] = (e->s->dist[i] > sol[2]) ? sol[2] : e->s->dist[i];
			}
		}

		if (tmp != e->s->dist[i])
			*((unsigned int *)e->data_img + i) = color;




	}
}
