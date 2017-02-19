# include <rtv1.h>

void	set_cylindre(char **tmp, t_obj *o)
{
	t_cyl	*begin;
	float	save;
	float	tmp_vect[3];
	
	if (o->cy == NULL)
	{
		o->cy = (t_cyl *)malloc(sizeof(t_cyl));
		begin = o->cy;
	}
	else
	{
		begin = o->cy;
		while (o->cy->next != NULL)
			o->cy = o->cy->next;
		o->cy->next = (t_cyl *)malloc(sizeof(t_cyl));
		o->cy = o->cy->next;
	}
	o->cy->next = NULL;
	o->cy->origin = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[1], o->cy->origin);
	if (!ft_is_float(tmp[2]))
		not_a_valid_file();
	save = ft_atof(tmp[2]);
	vectorial_sum(o->cy->origin, o->cy->origin, vectorial_multi(tmp_vect, save, load_vect(tmp[3], tmp_vect)));
	o->cy->axe = (float *)malloc(sizeof(float) * 3);
	set_vect(o->cy->axe, 0, 0, 1);
	if (!ft_is_float(tmp[4]))
		not_a_valid_file();
	save = ft_atof(tmp[4]);
	save = (save) ? M_PI / save : 0;
	if (save)
		rot(o->cy->axe, save, load_vect(tmp[5], tmp_vect));
	if (!ft_is_float(tmp[6]))
		not_a_valid_file();
	o->cy->r = ft_atof(tmp[6]);
	o->cy->color = ft_atoi_hexa(tmp[7]);
	o->cy->borne = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[8], o->cy->borne);
	set_cyl_transfer(o->cy);
	if (!(ft_is_float(tmp[9]) && ft_is_float(tmp[10])))
		not_a_valid_file();
	o->cy->id_light = (ft_atof(tmp[9]) == 42) ? 42 : 0;
	o->cy->light_coef = ft_atof(tmp[10]);
	o->cy = begin;
}
