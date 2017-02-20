# include "rtv1.h"

static void	set_param(int i, float *param, t_env *e)
{
		param[0] = pow(e->o->co->t->cam_r_dir[i][0], 2)
			+ pow(e->o->co->t->cam_r_dir[i][1], 2)
			- pow(e->o->co->t->cam_r_dir[i][2], 2);
		param[1] = 2 * (e->o->co->t->cam_r_dir[i][0]
			* (e->o->co->t->cam_pos[0] - e->o->co->t->obj_pos[0])
			+ e->o->co->t->cam_r_dir[i][1] * (e->o->co->t->cam_pos[1]
			- e->o->co->t->obj_pos[1]) - e->o->co->t->cam_r_dir[i][2]
			* (e->o->co->t->cam_pos[2] - e->o->co->t->obj_pos[2]));
		param[2] = pow(e->o->co->t->cam_pos[0]
			- e->o->co->t->obj_pos[0], 2)
			+ pow(e->o->co->t->cam_pos[1] - e->o->co->t->obj_pos[1], 2)
			- pow(e->o->co->t->cam_pos[2] - e->o->co->t->obj_pos[2], 2);
}

static float	solve(float *param)
{
	float	delt;
	float	tmp[2];
	float	sol;
	
	sol = MAX_DIST;
	if ((delt = pow(param[1], 2) - 4 * param[0] * param[2]) == 0)
		sol = ((tmp[0] = -param[1] / (2 * param[0])) >= VP_DIST)
			? tmp[0] : sol;
	else if (delt > 0)
	{
		tmp[0] = (-param[1] + sqrt(delt))/ (2 * param[0]);
		tmp[1] = (-param[1] - sqrt(delt))/ (2 * param[0]);
		if ((tmp[0] >= VP_DIST && tmp[1] < VP_DIST)
			|| (tmp[1] >= VP_DIST && tmp[0] < VP_DIST))
			sol = (tmp[0] >= VP_DIST) ? tmp[0] : tmp[1];
		else if (tmp[0] >= VP_DIST && tmp[1] >= VP_DIST)	
			sol = (tmp[0] <= tmp[1]) ? tmp[0] : tmp[1];
	}
	return (sol);
}

static void	sol_test(int i, float sol, t_env *e)
{
	float	tmp;

	if (sol <= e->c->r_dist[i] && sol < MAX_DIST)
	{
		tmp = e->o->co->t->cam_pos[2] + sol * e->o->co->t->cam_r_dir[i][2] - e->o->co->t->obj_pos[2];
		if (!e->o->co->borne
			|| (tmp < 0 && tmp >= e->o->co->borne[0])
			|| (tmp >= 0 && tmp <= e->o->co->borne[1]))
		{
			e->c->r_dist[i] = sol;
			e->c->obj[i] = e->o->co;
			ft_strcpy(e->c->name[i], "cone");
		}
	}
}

int	cone_test(t_env *e)
{
	int	i;
	float	param[3];
	float	sol;

	matrix_product(e->o->co->t->cam_pos, e->o->co->t->mat, e->c->pos);
	matrix_product(e->o->co->t->obj_pos, e->o->co->t->mat, e->o->co->origin);
	i = -1;
	while (++i < MAX_X * MAX_Y)
	{
		matrix_product(e->o->co->t->cam_r_dir[i], e->o->co->t->mat, e->c->r_dir[i]);
		set_param(i, param, e);
		sol = solve(param);
		sol_test(i, sol, e);
	}
	return (1);
}
