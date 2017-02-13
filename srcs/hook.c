# include "rtv1.h"


int	expose_hook(t_env *e)
{
	clear_img_dist(e);
	print_all(e);
	mlx_put_image_to_window(e->ptr, e->win, e->img, 0, 0);
	return (0);
}

int	key_hook(int keycode, t_env *e)
{
	float 	tmp[3];

	tmp[0] = e->c->base[2][0];
	tmp[1] = e->c->base[2][1];
	tmp[2] = e->c->base[2][2];
	if (keycode == EXIT)
		exit(0);
	else if (keycode == AVANCER)
		vectorial_sum(e->c->pos, e->c->pos, vectorial_multi(tmp, 5));
	else if (keycode == RECULER)
		vectorial_subtraction(e->c->pos, e->c->pos, vectorial_multi(tmp, 5));
	else if (keycode == ROT_D || keycode == ROT_D2)
	{	
		rot_d(e->c->base[2]);
		set_cam_base(e->c);
		set_cam_ray_dir(e->c);
	}
	else if (keycode == ROT_G || keycode == ROT_G2)
	{	
		rot_g(e->c->base[2]);
		set_cam_base(e->c);
		set_cam_ray_dir(e->c);
	}
	else if (keycode == BAS || keycode == BAS2)
	{	
		rot_b(e->c->base);
		vectorial_product(e->c->base[1], e->c->base[2], e->c->base[0]);
		set_cam_ray_dir(e->c);
	}
	else if (keycode == HAUT || keycode == HAUT2)
	{	
		rot_h(e->c->base);
		vectorial_product(e->c->base[1], e->c->base[2], e->c->base[0]);
		set_cam_ray_dir(e->c);
	}
	expose_hook(e);
	return (0);	
}
