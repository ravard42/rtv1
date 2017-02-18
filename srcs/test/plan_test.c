# include "rtv1.h"

static float	solve(int i, t_env *e)
{
	float	tmp;

	tmp = (e->o->p->nor[0] * (e->o->p->origin[0] - e->c->pos[0])
	+ e->o->p->nor[1] * (e->o->p->origin[1] - e->c->pos[1])
	+ e->o->p->nor[2] * (e->o->p->origin[2] - e->c->pos[2]))
	/ (e->o->p->nor[0] * e->c->r_dir[i][0]
	+ e->o->p->nor[1] * e->c->r_dir[i][1]
	+ e->o->p->nor[2] * e->c->r_dir[i][2]);
	return (tmp);
}

static void	sol_test(int i, float sol, t_env *e)
{
	float	tmp[3];
	
	if (sol <= e->c->r_dist[i] && sol < MAX_DIST)
	{
		vectorial_sum(tmp, e->c->pos, vectorial_multi(tmp, sol, e->c->r_dir[i]));
		if (!e->o->p->borne[0] || ft_dist(e->o->p->origin, tmp) <= e->o->p->borne[1])
		{
			e->c->r_dist[i] = sol;
			e->c->obj[i] = e->o->p;
			ft_strcpy(e->c->name[i], "plan");
		}
	}
}

int	plan_test(t_env *e)
{
	int	i;
	float	tmp;
	float	sol;
	
	i = -1;
	sol = MAX_DIST;
	while (++i < MAX_X * MAX_Y)
	{
		if (scalar_product(e->o->p->nor, e->c->r_dir[i]))
			sol = ((tmp = solve(i, e)) >= VP_DIST) ? tmp : MAX_DIST;
		sol_test(i, sol, e);
	}
	return (1);
}
