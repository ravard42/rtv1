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
	if (!ft_is_float(tmp[3]))
		not_a_valid_file();
	o->p->val = ft_atof(tmp[3]);
	o->p->rot = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[4], o->p->rot);
	if (!ft_is_float(tmp[5]))
		not_a_valid_file();
	o->p->translate = ft_atof(tmp[5]);
	o->p->color = ft_atoi_hexa(tmp[6]);
	o->p->borne = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[7], o->p->borne);
	o->p = begin;
}
