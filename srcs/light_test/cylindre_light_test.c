# include "rtv1.h"

static void	set_param(float *param, t_cyl *cy)
{
	param[0] = pow(cy->t->cam_r_dir[0][0], 2)
		+ pow(cy->t->cam_r_dir[0][1], 2);
	param[1] = 2 * (cy->t->cam_r_dir[0][0]
			* (cy->t->cam_pos[0] - cy->t->obj_pos[0])
			+ cy->t->cam_r_dir[0][1] * (cy->t->cam_pos[1]
				- cy->t->obj_pos[1]));
	param[2] = pow(cy->t->cam_pos[0]
			- cy->t->obj_pos[0], 2)
		+ pow(cy->t->cam_pos[1] - cy->t->obj_pos[1], 2)
		- pow(cy->r, 2);
}

static float	solve(float *param)
{
	float	delt;
	float	tmp[2];
	float	sol;

	sol = -42;
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

int	cylindre_light_test(float *p, void *obj, t_cyl *cy, t_lght *l)
{
	float	tmp[2];
	float	param[3];

	if (obj == cy || l->id == cy->id_light || cy->ombre == 0)
		return (1);
	tmp[0] = ft_dist(p, l->origin);
	vectorial_subtraction(param, p, l->origin);
	ft_norme(param);
	matrix_product(cy->t->cam_pos, cy->t->mat, l->origin);
	matrix_product(cy->t->obj_pos, cy->t->mat, cy->origin);
	matrix_product(cy->t->cam_r_dir[0], cy->t->mat, param);
	set_param(param, cy);
	if ((tmp[1] = solve(param)) == -42 || tmp[1] >= tmp[0])
		return (1);
	else if (cy->borne)
	{
		tmp[0] = cy->t->cam_pos[2] + tmp[1]
			* cy->t->cam_r_dir[0][2] - cy->t->obj_pos[2];
		if ((tmp[0] < 0 && tmp[0] < cy->borne[0]) 
				|| (tmp[0] > 0 && tmp[0] > cy->borne[1]))
			return (1);
	}
	return (0);
}
