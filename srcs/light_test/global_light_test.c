# include "rtv1.h"

static void	save(t_env *e, void **tmp)
{
	tmp[0] = e->o->s;
	tmp[1] = e->o->p;
	tmp[2] = e->o->cy;
	tmp[3] = e->o->co;
}

static void	recup(t_env *e, void **tmp)
{
	e->o->s = tmp[0];
	e->o->p = tmp[1];
	e->o->cy = tmp[2];
	e->o->co = tmp[3];
}

static void	test_all_object(int *light, float *p, void *obj, t_env *e)
{
	while (e->o->s != NULL &&
			(*light = sphere_light_test(p, obj, e->o->s, e->l)))
		e->o->s = e->o->s->next;
	while (e->o->p != NULL && *light &&
			(*light = plan_light_test(p, obj, e->o->p, e->l)))
		e->o->p = e->o->p->next;
	while (e->o->cy != NULL && *light &&
			(*light = cylindre_light_test(p, obj, e->o->cy, e->l)))
		e->o->cy = e->o->cy->next;
	while (e->o->co != NULL && *light &&
			(*light = cone_light_test(p, obj, e->o->co, e->l)))
		e->o->co = e->o->co->next;

}

void	global_light_test(float *p, void *obj, t_env *e)
{
	void	*tmp[4];
	int	light[1];
	t_lght	*begin;

	save(e, tmp);
	begin = e->l;
	while (e->l != NULL)
	{
		*light = 1;
		test_all_object(light, p, obj, e);
		if (*light)
			e->l->scope = 1;
		e->l = e->l->next;
		recup(e, tmp);
	}
	e->l = begin;
}
