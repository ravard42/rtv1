# include "rtv1.h"

void	set_light(char **tmp, t_env *e)
{
	t_lght	*begin;
	
	if (e->l == NULL)
	{
		e->l = (t_lght *)malloc(sizeof(t_lght));
		begin = e->l;
	}
	else
	{
		begin = e->l;
		while (e->l->next != NULL)
			e->l = e->l->next;
		e->l->next = (t_lght *)malloc(sizeof(t_lght));
		e->l = e->l->next;
	}
	e->l->next = NULL;
	e->l->name = "light";
	e->l->origin = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[1], e->l->origin);
	e->l->color = ft_atoi_hexa(tmp[2]);
	e->l->scope = 0;
	e->l = begin;
}
