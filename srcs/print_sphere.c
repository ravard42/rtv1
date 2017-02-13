# include "rtv1.h"

static void	set_param(int i, float *param, t_env *e)
{		
		param[0] = pow(e->c->r_dir[i][0], 2)
			+ pow(e->c->r_dir[i][1], 2)
			+ pow(e->c->r_dir[i][2], 2);
		param[1] = 2 * (e->c->r_dir[i][0]
			* (e->c->pos[0] - e->o->s->origin[0])
			+ e->c->r_dir[i][1] * (e->c->pos[1]
			- e->o->s->origin[1]) + e->c->r_dir[i][2]
			* (e->c->pos[2] - e->o->s->origin[2]));
		param[2] = pow(e->c->pos[0]
			- e->o->s->origin[0], 2) + pow(e->c->pos[1]
			- e->o->s->origin[1], 2) + pow(e->c->pos[2]
			- e->o->s->origin[2], 2) - pow(e->o->s->r, 2);
}

static float	solve(float tmp, float *param)
{
	float	delt;
	float	sol[3];

	if ((delt = pow(param[1], 2) - 4 * param[0] * param[2]) == 0)
	{
		sol[0] = -param[1] / (2 * param[0]);
		tmp = (sol[0] > VP_DIST  && tmp > sol[0]) ? sol[0] : tmp;
	}
	else if (delt > 0)
	{
		sol[0] = (-param[1] + sqrt(delt)) / (2 * param[0]);
		sol[1] = (-param[1] - sqrt(delt)) / (2 * param[0]);
		if ((sol[0] <= VP_DIST && sol[1] > VP_DIST)
			|| (sol[0] > VP_DIST && sol[1] <= VP_DIST))
		{
			sol[2] = (sol[0] > VP_DIST) ? sol[0] : sol[1];
			tmp = (tmp > sol[2]) ? sol[2] : tmp;
		}
		else if (sol[0] > VP_DIST && sol[1] > VP_DIST)	
		{
			sol[2] = (sol[0] <= sol[1]) ? sol[0] : sol[1];
			tmp = (tmp > sol[2]) ? sol[2] : tmp;
		}
	}
	return (tmp);
}

void	print_sphere(t_env *e)
{
	int	i;
	float	tmp;
	float	param[3];

	i = -1;
	while (++i < MAX_X * MAX_Y)
	{
		set_param(i, param, e);
		tmp = solve(e->c->r_dist[i], param);
		if (tmp != e->c->r_dist[i] && (e->c->r_dist[i] = tmp))
			*((unsigned int *)e->data_img + i) = e->o->s->color;

	}
}
