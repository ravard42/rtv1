# include "rtv1.h"

static void	set_param(float *param, float *dir, t_sph *s, t_lght *l)
{		
		param[0] = pow(dir[0], 2)
			+ pow(dir[1], 2)
			+ pow(dir[2], 2);
		param[1] = 2 * (dir[0]
			* (l->origin[0] - s->origin[0])
			+ dir[1] * (l->origin[1]
			- s->origin[1]) + dir[2]
			* (l->origin[2] - s->origin[2]));
		param[2] = pow(l->origin[0]
			- s->origin[0], 2) + pow(l->origin[1]
			- s->origin[1], 2) + pow(l->origin[2]
			- s->origin[2], 2) - pow(s->r, 2);
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

int	sphere_light_test(float *p, void *obj, t_sph *s, t_lght *l)
{
	float	dist;
	float	dir[3];
	float	param[3];
	float	sol;

	if (obj == s || s->light)
		return (1);
	else
	{
		dist = ft_dist(p, l->origin);
		vectorial_subtraction(dir, p, l->origin);
		ft_norme(dir);
		set_param(param, dir, s, l);
		if ((sol = solve(param)) == -42 || sol >= dist)
			return (1);
	}
	return (0);

}
