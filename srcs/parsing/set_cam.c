# include "rtv1.h"

void	set_cam_base(t_cam *c)
{
	int		sens;
	//float		tmp[3];
	//float		cos_angle;

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
		if (c->base[0][0] == 0 && c->base[0][1] == 0 && c->base[0][2] == 0)
		{
			sens = (c->base[2][2] > 0) ? 1 : -1;
			c->base[0][0] = 0;
			c->base[0][1] = 1;
			c->base[0][2] = 0;
			c->base[1][0] = -sens;
			c->base[1][1] = 0;
			c->base[1][2] = 0;
		}
		else
			vectorial_product(c->base[1], c->base[2], c->base[0]);
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

void	set_cam(char **tmp, t_env *e)
{
	int	i;

	if (e->c)
		not_a_valid_file();
	e->c = (t_cam *)malloc(sizeof(t_cam));
	e->c->pos = (float *)malloc(sizeof(float) * 3);
	e->c->base = (float **)malloc(sizeof(float *) * 3);
	e->c->r_dir = (float **)malloc(sizeof(float *) * MAX_X * MAX_Y);
	e->c->r_dist = (float *)malloc(sizeof(float) * MAX_X * MAX_Y);
	e->c->obj = (void **)malloc(sizeof(void *) * MAX_X * MAX_Y);
	e->c->name = (char **)malloc(sizeof(char *) * MAX_X * MAX_Y);
	i = -1;
	while (++i < 3)
		e->c->base[i] = (float *)ft_memalloc(sizeof(float) * 3);
	i = -1;
	while (++i < MAX_X * MAX_Y)
	{
		e->c->r_dir[i] = (float *)malloc(sizeof(float) * 3);
		e->c->name[i] = (char *)ft_memalloc(sizeof(char) * 9);
	}
	load_vect(tmp[1], e->c->pos);
	load_vect(tmp[2], e->c->base[2]);
	ft_norme(e->c->base[2]);
	set_cam_base(e->c);
	set_cam_ray_dir(e->c);
}
