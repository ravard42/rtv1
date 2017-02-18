# include <rtv1.h>

void	set_plan(char **tmp, t_obj *o)
{
	t_pln	*begin;
	float	angle;
	float	cpy[3];

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
	o->p->origin = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[1], o->p->origin);
	o->p->nor = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[2], o->p->nor);
	ft_norme(o->p->nor);
	if (!ft_is_float(tmp[3]))
		not_a_valid_file();
	o->p->val = ft_atof(tmp[3]);
	o->p->rot = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[4], o->p->rot);
	angle = (o->p->val) ? M_PI / o->p->val : 0;
	if (o->p->val)
	{
		set_vect(o->p->nor, 0, 0, 1);
		rot(o->p->nor, angle, o->p->rot);
	}
	ft_norme(o->p->nor);
	if (!ft_is_float(tmp[5]))
		not_a_valid_file();
	o->p->translate = ft_atof(tmp[5]);
	vectorial_sum(o->p->origin, o->p->origin,
		vectorial_multi(cpy, o->p->translate, o->p->nor));
	if (o->p->translate < 0)
		vectorial_multi(o->p->nor, -1, o->p->nor);
	o->p->color = ft_atoi_hexa(tmp[6]);
	o->p->borne = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[7], o->p->borne);
	o->p = begin;
}
