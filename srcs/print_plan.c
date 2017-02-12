# include "rtv1.h"

void	print_plan(t_env *e)
{
	int	i;
	float	tmp[2];
	
	i = -1;
	while (++i < MAX_X * MAX_Y)
	{
		tmp[0] = e->c->r_dist[i];
		tmp[1] = (e->o->p->nor[0] * (e->o->p->origin[0] - e->c->pos[0]) + e->o->p->nor[1] * (e->o->p->origin[1] - e->c->pos[1]) + e->o->p->nor[2] * (e->o->p->origin[2] - e->c->pos[2])) / (e->o->p->nor[0] * e->c->r_dir[i][0] + e->o->p->nor[1] * e->c->r_dir[i][1] + e->o->p->nor[2] * e->c->r_dir[i][2]);
		e->c->r_dist[i] = (tmp[1] > VP_DIST && tmp[1] < e->c->r_dist[i]) ? tmp[1] : e->c->r_dist[i];
		if (tmp[0] != e->c->r_dist[i])
			*((int *)e->data_img + i) = e->o->p->color;

	}
}
