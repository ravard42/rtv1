# include <rtv1.h>

void	set_plan(char **tmp, t_obj *o)
{
	t_pln	*begin;
	float	save;
	float	tmp_vect[3];

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
	if (!ft_is_float(tmp[2]))
		not_a_valid_file();
	save = ft_atof(tmp[2]);
	vectorial_sum(o->p->origin, o->p->origin, vectorial_multi(tmp_vect, save, load_vect(tmp[3], tmp_vect)));
	o->p->nor = (float *)malloc(sizeof(float) * 3);
	set_vect(o->p->nor, 0, 0, 1);
	if (!ft_is_float(tmp[4]))
		not_a_valid_file();
	save = ft_atof(tmp[4]);
	save = (save) ? M_PI / save : 0;
	if (save)
		rot(o->p->nor, save, load_vect(tmp[5], tmp_vect));
	if (!ft_is_float(tmp[6]))
		not_a_valid_file();
	save = ft_atof(tmp[6]);
	vectorial_sum(o->p->origin, o->p->origin,
		vectorial_multi(tmp_vect, save, o->p->nor));
	if (save < 0)
		vectorial_multi(o->p->nor, -1, o->p->nor);
	o->p->color = ft_atoi_hexa(tmp[7]);
	o->p->borne = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[8], o->p->borne);
	if (!ft_is_float(tmp[9]))
		not_a_valid_file();
	o->p->coef = ft_atof(tmp[9]);
	o->p = begin;
}
