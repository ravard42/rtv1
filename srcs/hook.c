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

	tmp[0] = e->s->base[2][0];
	tmp[1] = e->s->base[2][1];
	tmp[2] = e->s->base[2][2];
	if (keycode == EXIT)
		exit(0);
	else if (keycode == AVANCER)
		vectorial_sum(e->s->cam, vectorial_multi(5, tmp), e->s->cam);
	else if (keycode == RECULER)
		vectorial_subtraction(e->s->cam, vectorial_multi(5, tmp), e->s->cam);
	else if (keycode == ROT_D || keycode == ROT_D2)
	{	
		rot_d(e->s->base[2]);
		set_base(e->s);
		set_dir(e);
	}
	else if (keycode == ROT_G || keycode == ROT_G2)
	{	
		rot_g(e->s->base[2]);
		set_base(e->s);
		set_dir(e);
	}
	else if (keycode == BAS || keycode == BAS2)
	{	
		rot_b(e->s->base);
		vectorial_product(e->s->base[2], e->s->base[0], e->s->base[1]);
		set_dir(e);
	}
	else if (keycode == HAUT || keycode == HAUT2)
	{	
		rot_h(e->s->base);
		vectorial_product(e->s->base[2], e->s->base[0], e->s->base[1]);
		set_dir(e);
	}
	expose_hook(e);
	return (0);	
}
