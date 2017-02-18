# include <rtv1.h>

void	set_cone(char **tmp, t_obj *o)
{
	t_con	*begin;
	float	angle;
	
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
	o->co->val = ft_atof(tmp[2]);
	o->co->rot = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[3], o->co->rot);
	o->co->axe = (float *)malloc(sizeof(float) * 3);
	set_vect(o->co->axe, 0, 0, 1);
	angle = (o->co->val) ? M_PI / o->co->val : 0;
	if (angle)
		rot(o->co->axe, angle, o->co->rot);
	ft_norme(o->co->axe);
	o->co->color = ft_atoi_hexa(tmp[4]);
	o->co->borne = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[5], o->co->borne);
	set_cone_transfer(o->co);
	o->co = begin;
}
