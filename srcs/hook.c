# include "rtv1.h"


int	expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->ptr, e->win, e->img, 0, 0);
	return (0);
}

int	key_hook(int keycode, t_env *e)
{
	if (e)
		;
	if (keycode == EXIT)
		exit(0);
	return (0);	
}
