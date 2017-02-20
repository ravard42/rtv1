# include "rtv1.h"

static float	solve(t_lght *l, float *dir, t_pln *p)
{
	float	tmp;

	tmp = (p->nor[0] * (p->origin[0] - l->origin[0])
	+ p->nor[1] * (p->origin[1] - l->origin[1])
	+ p->nor[2] * (p->origin[2] - l->origin[2]))
	/ (p->nor[0] * dir[0]
	+ p->nor[1] * dir[1]
	+ p->nor[2] * dir[2]);
	return (tmp);
}

int	plan_light_test(float *p, void *obj, t_pln *pl, t_lght *l)
{
	float 	dist;
	float	dir[3];
	float	tmp[3];
	float	sol;

	if (obj == pl || pl->ombre == 0)
		return (1);
	else
	{
		dist = ft_dist(p, l->origin);
		vectorial_subtraction(dir, p, l->origin);
		ft_norme(dir);
		sol = -42;
		if (scalar_product(pl->nor, dir))
			sol = solve(l, dir, pl);
		else
			return (1);
		if ((sol <= 0) || sol >= dist)
			return (1);
		else if (pl->borne)
		{
			vectorial_sum(tmp, l->origin, vectorial_multi(tmp, sol, dir));
			if (ft_dist(pl->origin, tmp) > pl->borne[0])
				return (1);
		}
	}
	return (0);
}
