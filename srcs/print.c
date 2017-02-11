# include "rtv1.h"

void		print_all(t_env *e)
{
	t_sph	*tmp;

	tmp = e->o->s;
	while (tmp != NULL)
	{
		print_sphere(tmp->origin, tmp->r, e, tmp->color);
		tmp = tmp->next;
	}

	/*	
	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
	n[0] = 0;
	n[1] = 0;
	n[2] = 1;
	print_plan(c, n, e, 0x111111);
	
	n[0] = 1;
	n[1] = 0;
	n[2] = 0;
	print_plan(c, n, e, 0x555555);
	
	n[0] = 0;
	n[1] = 1;
	n[2] = 0;
	print_plan(c, n, e, 0xAAAAAA);

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
