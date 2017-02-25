# include "rtv1.h"

void		loop(t_env *e)
{
	mlx_expose_hook(e->win, &expose_hook, e);
	mlx_key_hook(e->win, &key_hook, e);
	mlx_hook(e->win, 17, 1L << 17, &ft_exit, e);
	mlx_loop(e->ptr);
}
