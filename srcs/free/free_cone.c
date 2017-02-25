# include "rtv1.h"

static void	free_cone(t_con *co)
{
	int	i;

	i = -1;
	while (++i < MAX_X * MAX_Y)
		free(co->t->cam_r_dir[i]);
	free(co->t->cam_r_dir);
	i = -1;
	while (++i < 3)
		free(co->t->mat[i]);
	free(co->t->mat);
	free(co->t->obj_pos);
	free(co->t->cam_pos);
	free(co->t);
	free(co->axe);
	free(co->origin);
	if (co->borne)
		free(co->borne);
}

int	free_all_cone(t_obj *o)
{
	t_con 		*begin;

	if (!o->co)
		return (0);
	begin = o->co;
	free_cone(o->co);
	while ((o->co = o->co->next) != NULL)
		free_cone(o->co);
	o->co = begin;
	while (begin->next != NULL)
	{
		while (o->co->next->next != NULL)
			o->co = o->co->next;
		free(o->co->next);
		o->co->next = NULL;
		o->co = begin;
	}
	free(o->co);
	o->co = NULL;
	return (1);
}
