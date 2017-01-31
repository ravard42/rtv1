# include "rtv1.h"


int	expose_hook(t_env *e)
{
	print_all(e);
	mlx_put_image_to_window(e->ptr, e->win, e->img, 0, 0);
	return (0);
}

int	key_hook(int keycode, t_env *e)
{
	if (e)
		;
	if (keycode == EXIT)
		exit(0);
	else if (keycode == 100 || keycode == 65363)
	{	
		matrix_sum(e->s->base[2], e->s->base[0]);
		set_base(e->s);
		set_dir(e);
	}
	else if (keycode == 97 || keycode == 65361)
	{	
		matrix_subtraction(e->s->base[2], e->s->base[0]);
		set_base(e->s);
		set_dir(e);
	}
	expose_hook(e);
	return (0);	
}
