# include <rtv1.h>

void	set_cone(char **tmp, t_obj *o)
{
	t_con	*begin;
	float	save;
	float	tmp_vect[3];
	
	if (o->co == NULL)
	{
		o->co = (t_con *)malloc(sizeof(t_con));
		begin = o->co;
	}
	else
	{
		begin = o->co;
		while (o->co->next != NULL)
			o->co = o->co->next;
		o->co->next = (t_con *)malloc(sizeof(t_con));
		o->co = o->co->next;
	}
	o->co->next = NULL;
	o->co->origin = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[1], o->co->origin);
	if (!ft_is_float(tmp[2]))
		not_a_valid_file();
	save = ft_atof(tmp[2]);
	vectorial_sum(o->co->origin, o->co->origin, vectorial_multi(tmp_vect, save, load_vect(tmp[3], tmp_vect)));
	o->co->axe = (float *)malloc(sizeof(float) * 3);
	set_vect(o->co->axe, 0, 0, 1);
	if (!ft_is_float(tmp[4]))
		not_a_valid_file();
	save = ft_atof(tmp[4]);
	save = (save) ? M_PI / save : 0;
	if (save)
		rot(o->co->axe, save, load_vect(tmp[5], tmp_vect));
	o->co->color = ft_atoi_hexa(tmp[6]);
	o->co->borne = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[7], o->co->borne);
	set_cone_transfer(o->co);
	o->co = begin;
}
