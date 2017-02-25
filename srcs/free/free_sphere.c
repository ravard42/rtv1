# include "rtv1.h"

int	free_sphere(t_obj *o)
{
	t_sph 		*begin;

	if (!o->s)
		return (0);
	begin = o->s;
	free(o->s->origin);
	while ((o->s = o->s->next) != NULL)
		free(o->s->origin);
	o->s = begin;
	while (begin->next != NULL)
	{
		while (o->s->next->next != NULL)
			o->s = o->s->next;
		free(o->s->next);
		o->s->next = NULL;
		o->s = begin;
	}
	free(o->s);
	o->s = NULL;
	return (1);
}


