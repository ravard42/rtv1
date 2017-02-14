# include "rtv1.h"

void	print_plan(t_env *e)
{
	int	i;
	float	sol;
	float	tmp[3];
	
	i = -1;
	while (++i < MAX_X * MAX_Y)
	{
		sol = MAX_DIST;
		tmp[0] = (e->o->p->nor[0] * (e->o->p->origin[0] - e->c->pos[0])
			+ e->o->p->nor[1] * (e->o->p->origin[1] - e->c->pos[1])
			+ e->o->p->nor[2] * (e->o->p->origin[2] - e->c->pos[2]))
			/ (e->o->p->nor[0] * e->c->r_dir[i][0]
			+ e->o->p->nor[1] * e->c->r_dir[i][1]
			+ e->o->p->nor[2] * e->c->r_dir[i][2]);
		sol = (tmp[0] >= VP_DIST) ? tmp[0] : sol;
		if (sol < e->c->r_dist[i])
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
}
