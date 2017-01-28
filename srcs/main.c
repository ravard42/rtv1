# include "rtv1.h"

int	main()
{
	t_env		*e;
	int		info[3];
	float		c[3];
	float		n[3];
	float		r;

	e = (t_env *)malloc(sizeof(t_env));
	e->ptr = mlx_init();
	e->win = mlx_new_window(e->ptr, MAX_X, MAX_Y, "rtv1");
	e->img = mlx_new_image(e->ptr, MAX_X, MAX_Y);
	e->data_img = mlx_get_data_addr(e->img, info, info + 1, info + 2);
	set_dir_dist(e);
	
	c[0] = 0;
	c[1] = 0;
	c[2] = 12;
	r = 1;

	print_sphere(c, r, e, 0x00FF00);
	n[0] = -1;
	n[1] = -2;
	n[2] = 1;

	print_plan(c, n, e, 0x4A4A4A);
	c[0] += 3;
	print_sphere(c, r, e, 0xFFFF00);
	c[0] -= 6;
	c[2] -= 3;
	print_sphere(c, r, e, 0x00FFFF);
	c[0] = 0;
	c[1] = 2;
	c[2] = 0;
	n[0] = 0;
	n[1] = -1;
	n[2] = 0;
	print_plan(c, n, e, 0xA3A3A3);

	
	expose(e);
	return (0);
}
