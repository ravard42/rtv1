# include "rtv1.h"

void	init_cam(float *pos_cam, float *dir_cam, t_scn *s)
{
	s->cam[0] = pos_cam[0];
	s->cam[1] = pos_cam[1];
	s->cam[2] = pos_cam[2];
	s->base[2][0] = dir_cam[0];
	s->base[2][1] = dir_cam[1];
	s->base[2][2] = dir_cam[2];
	ft_norme(s->base[2]);
}

t_env		*init_env(float *cam, float *dir_cam)
{
	t_env	*e;
	int	info[3];
	int	i;

	e = (t_env *)malloc(sizeof(t_env));
	e->ptr = mlx_init();
	e->win = mlx_new_window(e->ptr, MAX_X, MAX_Y, "rtv1");
	e->img = mlx_new_image(e->ptr, MAX_X, MAX_Y);
	e->data_img = mlx_get_data_addr(e->img, info, info + 1, info + 2);
	e->s = (t_scn *)malloc(sizeof(t_scn));
	e->s->cam = (float *)malloc(sizeof(float) * 3);
	e->s->base = (float **)malloc(sizeof(float *) * 3);
	i = -1;
	while (++i < 3)
		e->s->base[i] = (float *)malloc(sizeof(float) * 3);
	e->s->dir = (float **)malloc(sizeof(float *) * MAX_X * MAX_Y);
	i = -1;
	while (++i < MAX_X * MAX_Y)
		e->s->dir[i] = (float *)malloc(sizeof(float) * 3);
	e->s->dist = (float *)malloc(sizeof(float) * MAX_X * MAX_Y);
	
	init_cam(cam, dir_cam, e->s);
	set_base(e->s);
	set_dir(e);

	return (e);
}
