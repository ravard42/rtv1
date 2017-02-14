# include <rtv1.h>

void	set_cone(char **tmp, t_obj *o)
{
	t_con	*begin;
	
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
	if (!ft_is_int(tmp[2]))
		not_a_valid_file();
	o->co->val = ft_atoi(tmp[2]);
	o->co->rot = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[3], o->co->rot);
	o->co->color = ft_atoi_hexa(tmp[4]);
	o->co->borne = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[5], o->co->borne);
	o->co = begin;
}
