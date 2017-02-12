# include "rtv1.h"

void		save(t_env *e, void **tmp)
{
	tmp[0] = e->o->s;
	tmp[1] = e->o->p;
	tmp[2] = e->o->cy;
	tmp[3] = e->o->co;
}

void		recup(t_env *e, void **tmp)
{
	e->o->s = tmp[0];
	e->o->p = tmp[1];
	e->o->cy = tmp[2];
	e->o->co = tmp[3];
}


void		print_all(t_env *e)
{
	void	**tmp;

	tmp = (void **)malloc(sizeof(void *) * 4);
	save(e, tmp);
	while (e->o->s != NULL)
	{
		print_sphere(e);
		e->o->s = e->o->s->next;
	}
	while (e->o->p != NULL)
	{
		print_plan(e);
		e->o->p = e->o->p->next;
	}
	recup(e, tmp);

	/*	
	c[0] = 5;
	c[1] = 15;
	c[2] = 0;
	n[0] = 1;
	n[1] = 0;
	n[2] = 0;
	print_cyl(c, r, n, M_PI / 6, e, 0xFF00FF);
	
	c[0] = 12;
	c[1] = 12;
	c[2] = 7;
	n[0] = 1;
	n[1] = 0;
	n[2] = 0;


	a[0] = 1;
	a[1] = 1;
	a[2] = 9;	
	print_cone(c, a, n, -M_PI / 6, e, 0x00FFFF);
	*/
}
