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
	c[2] = 10;
	r = 1;

	print_sphere(c, r, e, 0x00FF00);
	n[0] = -1;
	n[1] = -2;
	n[2] = 1;

	print_plan(c, n, e, 0xFF00FF);
	c[0] += 3;
	print_sphere(c, r, e, 0xFF0000);
	c[0] -= 6;
	c[1] += 3;
	c[2] += 0.8;
	print_sphere(c, r, e, 0x0000FF);
	
	expose(e);
	return (0);
}
