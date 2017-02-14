# include <rtv1.h>

void	set_plan(char **tmp, t_obj *o)
{
	t_pln	*begin;

	if (o->p == NULL)
	{
		o->p = (t_pln *)malloc(sizeof(t_pln));
		begin = o->p;
	}
	else
	{
		begin = o->p;
		while (o->p->next != NULL)
			o->p = o->p->next;
		o->p->next = (t_pln *)malloc(sizeof(t_pln));
		o->p = o->p->next;
	}
	o->p->next = NULL;
	o->p->name = "plan";
	o->p->origin = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[1], o->p->origin);
	o->p->nor = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[2], o->p->nor);
	o->p->color = ft_atoi_hexa(tmp[3]);
	o->p->borne = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[4], o->p->borne);
	o->p = begin;
}
