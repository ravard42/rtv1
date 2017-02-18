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

void		global_test(t_env *e)
{
	void	*tmp[4];

	save(e, tmp);
	while (e->o->s != NULL && sphere_test(e))
		e->o->s = e->o->s->next;
	while (e->o->p != NULL && plan_test(e))
		e->o->p = e->o->p->next;
	while (e->o->cy != NULL && cylindre_test(e))
		e->o->cy = e->o->cy->next;
	while (e->o->co != NULL && cone_test(e))
		e->o->co = e->o->co->next;
	recup(e, tmp);
}
