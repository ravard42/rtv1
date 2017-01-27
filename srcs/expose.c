# include "rtv1.h"

void		expose(t_env *e)
{
	mlx_expose_hook(e->win, &expose_hook, e);
	mlx_key_hook(e->win, &key_hook, e);
	mlx_loop(e->ptr);
}
