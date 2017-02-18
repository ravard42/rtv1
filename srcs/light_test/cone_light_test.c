# include "rtv1.h"

static void	set_param(float *param, t_con *co)
{
		param[0] = pow(co->t->cam_r_dir[0][0], 2)
			+ pow(co->t->cam_r_dir[0][1], 2)
			- pow(co->t->cam_r_dir[0][2], 2);
		param[1] = 2 * (co->t->cam_r_dir[0][0]
			* (co->t->cam_pos[0] - co->t->obj_pos[0])
			+ co->t->cam_r_dir[0][1] * (co->t->cam_pos[1]
			- co->t->obj_pos[1]) - co->t->cam_r_dir[0][2]
			* (co->t->cam_pos[2] - co->t->obj_pos[2]));
		param[2] = pow(co->t->cam_pos[0]
			- co->t->obj_pos[0], 2)
			+ pow(co->t->cam_pos[1] - co->t->obj_pos[1], 2)
			- pow(co->t->cam_pos[2] - co->t->obj_pos[2], 2);
}

static float	solve(float *param)
{
	float	delt;
	float	tmp[2];
	float	sol;
	
	sol = -42;;
	if ((delt = pow(param[1], 2) - 4 * param[0] * param[2]) == 0)
	{
		tmp[0] = -param[1] / (2 * param[0]);
		sol = (tmp[0] > 0) ? tmp[0] : sol;
	}
	else if (delt > 0)
	{
		tmp[0] = (-param[1] + sqrt(delt))/ (2 * param[0]);
		tmp[1] = (-param[1] - sqrt(delt))/ (2 * param[0]);
		if (tmp[0] > 0 && tmp[1] > 0) 
			sol = (tmp[0] <= tmp[1]) ? tmp[0] : tmp[1];
		else if ((tmp[0] > 0 && tmp[1] <= 0) 
			|| (tmp[1] > 0 && tmp[0] <= 0))
			sol = (tmp[0] > 0) ? tmp[0] : tmp[1];
	}
	return (sol);
}

int	cone_light_test(float *p, void *obj, t_con *co, t_lght *l)
{
	float	dist;
	float	dir[3];
	float	param[3];
	float	sol;

	if (obj == co)
		return (1);
	else
	{
		dist = ft_dist(p, l->origin);
		vectorial_subtraction(dir, p, l->origin);
		ft_norme(dir);
		matrix_product(co->t->cam_pos, co->t->mat, l->origin);
		matrix_product(co->t->obj_pos, co->t->mat, co->origin);
		matrix_product(co->t->cam_r_dir[0], co->t->mat, dir);
		set_param(param, co);
		if ((sol = solve(param)) == -42 || sol >= dist)
			return (1);
		else if (co->borne[0])
		{
			dist = co->t->cam_pos[2] + sol
				* co->t->cam_r_dir[0][2] - co->t->obj_pos[2];
			if ((dist < 0 && dist < co->borne[1]) 
				|| (dist > 0 && dist > co->borne[2]))
				return (1);
		}
	}
	return (0);
}
