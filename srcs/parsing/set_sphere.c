# include <rtv1.h>

void	set_sphere(char **tmp, t_obj *o)
{
	t_sph	*begin;
	float	val;
	float	translate[3];

	if (o->s == NULL)
	{
		o->s = (t_sph *)malloc(sizeof(t_sph));
		begin = o->s;
	}
	else
	{
		begin = o->s;
		while (o->s->next != NULL)
			o->s = o->s->next;
		o->s->next = (t_sph *)malloc(sizeof(t_sph));
		o->s = o->s->next;
	}
	o->s->next = NULL;
	o->s->origin = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[1], o->s->origin);
	if (!ft_is_float(tmp[2]))
		not_a_valid_file();
	val = ft_atof(tmp[2]);
	vectorial_sum(o->s->origin, o->s->origin, vectorial_multi(translate, val, load_vect(tmp[3], translate)));
	if (!ft_is_float(tmp[4]))
		not_a_valid_file();
	o->s->r = ft_atof(tmp[4]);
	o->s->color = ft_atoi_hexa(tmp[5]);
	if (!(ft_is_float(tmp[6]) && ft_is_float(tmp[7])))
		not_a_valid_file();
	o->s->id_light = (int)ft_atof(tmp[6]);
	o->s->light_coef = ft_atof(tmp[7]);
	o->s = begin;
}
