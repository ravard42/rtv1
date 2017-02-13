# include "rtv1.h"

static void	set_param(int i, float *param, t_env *e)
{
		param[0] = pow(e->t->cam_r_dir[i][0], 2)
			+ pow(e->t->cam_r_dir[i][1], 2);
		param[1] = 2 * (e->t->cam_r_dir[i][0]
			* (e->t->cam_pos[0] - e->t->obj_pos[0])
			+ e->t->cam_r_dir[i][1] * (e->t->cam_pos[1]
			- e->t->obj_pos[1]));
		param[2] = pow(e->t->cam_pos[0]
			- e->t->obj_pos[0], 2)
			+ pow(e->t->cam_pos[1] - e->t->obj_pos[1], 2)
			- pow(e->o->cy->r, 2);
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
		sol[0] = (-param[1] + sqrt(delt))/ (2 * param[0]);
		sol[1] = (-param[1] - sqrt(delt))/ (2 * param[0]);
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

void	print_cylindre(t_env *e)
{
	int	i;
	float	param[3];
	float	tmp;

	set_transfer_stuff(M_PI / e->o->cy->val, e->o->cy->rot, e->o->cy->origin, e);
	i = -1;
	while (++i < MAX_X * MAX_Y)
	{
		set_param(i, param, e);
		tmp = solve(e->c->r_dist[i], param);
		if (tmp != e->c->r_dist[i] && (e->c->r_dist[i] = tmp))
			*((unsigned int *)e->data_img + i) = e->o->cy->color;
	}
}
