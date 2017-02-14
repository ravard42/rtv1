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

static void	solve(float *param, float *sol)
{
	float	delt;
	float	tmp[2];
	
	if ((delt = pow(param[1], 2) - 4 * param[0] * param[2]) == 0)
		sol[0] = ((tmp[0] = -param[1] / (2 * param[0])) >= VP_DIST)
			? tmp[0] : sol[0];
	else if (delt > 0)
	{
		tmp[0] = (-param[1] + sqrt(delt))/ (2 * param[0]);
		tmp[1] = (-param[1] - sqrt(delt))/ (2 * param[0]);
		if ((tmp[0] >= VP_DIST && tmp[1] < VP_DIST)
			|| (tmp[1] >= VP_DIST && tmp[0] < VP_DIST))
			sol[0] = (tmp[0] >= VP_DIST) ? tmp[0] : tmp[1];
		else if (tmp[0] >= VP_DIST && tmp[1] >= VP_DIST)	
		{
			sol[0] = (tmp[0] <= tmp[1]) ? tmp[0] : tmp[1];
			sol[1] = (sol[0] == tmp[0]) ? tmp[1] : tmp[0];
		}
	}
}

static void	print(int i, float *sol, t_env *e)
{
	float	tmp[2];

	if (sol[0] < e->c->r_dist[i])
	{
		tmp[0] = e->t->cam_pos[2] + sol[0] * e->t->cam_r_dir[i][2] - e->t->obj_pos[2];
		if (e->o->cy->borne[0] == 0
			|| (tmp[0] < 0 && tmp[0] >= e->o->cy->borne[1])
			|| (tmp[0] >= 0 && tmp[0] <= e->o->cy->borne[2]))
		{
			e->c->r_dist[i] = sol[0];
			*((unsigned int *)e->data_img + i) = e->o->cy->color;
		}
		else if (sol[1] < e->c->r_dist[i])
		{
			tmp[1] = e->t->cam_pos[2] + sol[1] * e->t->cam_r_dir[i][2] - e->t->obj_pos[2];
			if ((tmp[1] < 0 && tmp[1] >= e->o->cy->borne[1])
				|| (tmp[1] >= 0 && tmp[1] <= e->o->cy->borne[2]))
			{
				e->c->r_dist[i] = sol[1];
				*((unsigned int *)e->data_img + i) = e->o->cy->color;
			}
		}
	}
}

void	print_cylindre(t_env *e)
{
	int	i;
	float	param[3];
	float	tmp;
	float	sol[2];

	tmp = (e->o->cy->val) ? M_PI / e->o->cy->val : 0;
	set_transfer_stuff(tmp, e->o->cy->rot, e->o->cy->origin, e);
	i = -1;
	while (++i < MAX_X * MAX_Y)
	{
		set_param(i, param, e);
		sol[0] = MAX_DIST;
		sol[1] = MAX_DIST;
		solve(param, sol);
		print(i, sol, e);
	}
}
