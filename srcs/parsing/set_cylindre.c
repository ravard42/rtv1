# include <rtv1.h>

void	set_cylindre(char **tmp, t_obj *o)
{
	t_cyl	*begin;
	float	angle;
	
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
	o->cy->r = ft_atof(tmp[2]);
	if (!ft_is_float(tmp[3]))
		not_a_valid_file();
	o->cy->val = ft_atof(tmp[3]);
	o->cy->rot = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[4], o->cy->rot);
	o->cy->axe = (float *)malloc(sizeof(float) * 3);
	set_vect(o->cy->axe, 0, 0, 1);
	angle = (o->cy->val) ? M_PI / o->cy->val : 0;
	if (angle)
		rot(o->cy->axe, angle, o->cy->rot);
	ft_norme(o->cy->axe);
	o->cy->color = ft_atoi_hexa(tmp[5]);
	o->cy->borne = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[6], o->cy->borne);
	set_cyl_transfer(o->cy);
	o->cy = begin;
}
