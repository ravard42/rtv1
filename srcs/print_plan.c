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

static void	print(int i, float sol, t_env *e)
{
	float	tmp[3];
	
	if (sol <= e->c->r_dist[i] && sol < MAX_DIST)
	{
		tmp[0] = e->c->pos[0] + sol * e->c->r_dir[i][0];
		tmp[1] = e->c->pos[1] + sol * e->c->r_dir[i][1];
		tmp[2] = e->c->pos[2] + sol * e->c->r_dir[i][2];
		if (!e->o->p->borne[0] || ft_dist(e->o->p->origin, tmp) <= e->o->p->borne[1])
		{
			e->c->r_dist[i] = sol;
			*((int *)e->data_img + i) = e->o->p->color;
		}
	}
}


void	print_plan(t_env *e)
{
	int	i;
	float	rot_value;
	float	tmp;
	float	sol;
	
	rot_value = (e->o->p->val) ? M_PI / e->o->p->val : 0;
	if (rot_value)
	{
		e->o->p->nor[0] = 0;
		e->o->p->nor[1] = 0;
		e->o->p->nor[2] = 1;
		rot(e->o->p->nor, rot_value, e->o->p->rot);
		ft_norme(e->o->p->nor);
	}
	i = -1;
	while (++i < MAX_X * MAX_Y)
	{
		sol = ((tmp = solve(i, e)) >= VP_DIST) ? tmp : MAX_DIST;
		print(i, sol, e);
	}
}
