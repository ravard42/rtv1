# include "rtv1.h"

static void	free_plan(t_pln *p)
{
	free(p->nor);
	free(p->origin);
	if (p->borne)
		free(p->borne);	
}


int	free_all_plan(t_obj *o)
{
	t_pln 		*begin;

	if (!o->p)
		return (0);
	begin = o->p;
	free_plan(o->p);
	while ((o->p = o->p->next) != NULL)
		free_plan(o->p);
	o->p = begin;
	while (begin->next != NULL)
	{
		while (o->p->next->next != NULL)
			o->p = o->p->next;
		free(o->p->next);
		o->p->next = NULL;
		o->p = begin;
	}
	free(o->p);
	o->p = NULL;
	return (1);
}


