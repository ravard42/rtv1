# include "rtv1.h"

void	set_cam_base(t_cam *c)
{
	int		sens;

	ft_norme(c->base[2]);
	if (c->base[2][1] == 0 && c->base[2][2] == 0)
	{
		sens = (c->base[2][0] > 0) ? 1 : -1;
		c->base[0][0] = 0;
		c->base[0][1] = -sens;
		c->base[0][2] = 0;
		c->base[1][0] = 0;
		c->base[1][1] = 0;
		c->base[1][2] = -1;
	}
	else if (c->base[2][0] == 0 && c->base[2][2] == 0)
	{
		sens = (c->base[2][1] > 0) ? 1 : -1;
		c->base[0][0] = sens;
		c->base[0][1] = 0;
		c->base[0][2] = 0;
		c->base[1][0] = 0;
		c->base[1][1] = 0;
		c->base[1][2] = -1;
	}
	else if (c->base[2][0] == 0 && c->base[2][1] == 0)
	{
		sens = (c->base[2][2] > 0) ? 1 : -1;
		c->base[0][0] = 0;
		c->base[0][1] = 1;
		c->base[0][2] = 0;
		c->base[1][0] = -sens;
		c->base[1][1] = 0;
		c->base[1][2] = 0;
	}
	else if (c->base[2][0] == 0)
	{
		sens = (c->base[2][1] > 0) ? 1 : -1;
		c->base[0][0] = sens;
		c->base[0][1] = 0;
		c->base[0][2] = 0;
		c->base[1][0] = 0;
		c->base[1][1] = c->base[2][2] * sens;
		c->base[1][2] = -c->base[2][1] * sens;
	}
	else if (c->base[2][1] == 0)
	{
		sens = (c->base[2][0] > 0) ? 1 : -1;
		c->base[0][0] = 0;
		c->base[0][1] = -sens;
		c->base[0][2] = 0;
		c->base[1][0] = c->base[2][2] * sens;
		c->base[1][1] = 0;
		c->base[1][2] = -c->base[2][0] * sens;
	}
	else
	{
		sens = (c->base[2][0] * c->base[2][1] > 0) ? 1 : -1;
		c->base[0][0] = sens / c->base[2][0];
		c->base[0][1] = -sens / c->base[2][1];
		c->base[0][2] = 0;
		ft_norme(c->base[0]);
		vectorial_product(c->base[1], c->base[2], c->base[0]);
	}
}

void	set_cam(char **tmp, t_cam *c)
{
	int	i;

	c->pos = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[1], c->pos);
	c->base = (float **)malloc(sizeof(float *) * 3);
	i = -1;
	while (++i < 3)
		c->base[i] = (float *)malloc(sizeof(float) * 3);
	load_vect(tmp[2], c->base[2]);
	ft_norme(c->base[2]);
	set_cam_base(c);
	c->r_dir = (float **)malloc(sizeof(float *) * MAX_X * MAX_Y);
	i = -1;
	while (++i < MAX_X * MAX_Y)
		c->r_dir[i] = (float *)malloc(sizeof(float) * 3);
	set_cam_ray_dir(c);
	c->r_dist = (float *)malloc(sizeof(float) * MAX_X * MAX_Y);
}
