# include "rtv1.h"

void		init_env(t_env *e)
{
	int	info[3];

	e->ptr = mlx_init();
	e->win = mlx_new_window(e->ptr, MAX_X, MAX_Y, "rtv1");
	e->img = mlx_new_image(e->ptr, MAX_X, MAX_Y);
	e->data_img = mlx_get_data_addr(e->img, info, info + 1, info + 2);
	e->c = (t_cam *)malloc(sizeof(t_cam));
	e->o = (t_obj *)malloc(sizeof(t_obj));
	e->o->s = NULL;
	e->o->p = NULL;
	e->o->cy = NULL;
	e->o->co = NULL;
}
