# include <rtv1.h>

void	set_sphere(char **tmp, t_obj *o)
{
	t_sph	*begin;

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
	o->s->r = ft_atof(tmp[2]);
	o->s->color = ft_atoi_hexa(tmp[3]);
	if (!ft_is_float(tmp[4]))
		not_a_valid_file();
	o->s->light = ft_atof(tmp[4]);
	o->s = begin;
}
