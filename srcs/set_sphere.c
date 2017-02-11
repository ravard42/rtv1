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
	o->s->r = ft_atoi(tmp[2]);
	o->s->color = ft_atoi_hexa(tmp[3]);
	o->s = begin;
}
