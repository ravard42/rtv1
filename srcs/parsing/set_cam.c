# include "rtv1.h"

static void	z_axe_cam_case(t_cam *c)
{
	int		sens;

	if (c->base[0][0] == 0 && c->base[0][1] == 0 && c->base[0][2] == 0)
	{
		sens = (c->base[2][2] > 0) ? 1 : -1;
		set_vect(c->base[0], 0, 1, 0);
		set_vect(c->base[1], -sens, 0, 0);
	}
	else
		vectorial_product(c->base[1], c->base[2], c->base[0]);
}

static void	x_y_z_axe_cam_case(t_cam *c)
{
	int		sens;

	if (c->base[2][0] == 0)
	{
		sens = (c->base[2][1] > 0) ? 1 : -1;
		set_vect(c->base[0], sens, 0, 0);
	}
	else if (c->base[2][1] == 0)
	{
		sens = (c->base[2][0] > 0) ? -1 : 1;
		set_vect(c->base[0], 0, sens, 0);
	}
	else
	{
		sens = (c->base[2][0] * c->base[2][1] > 0) ? 1 : -1;
		set_vect(c->base[0], sens / c->base[2][0],
				-sens / c->base[2][1], 0);
	}
	ft_norme(c->base[0]);
	vectorial_product(c->base[1], c->base[2], c->base[0]);
}

void	set_cam_base(t_cam *c)
{
	ft_norme(c->base[2]);
	if (c->base[2][0] == 0 && c->base[2][1] == 0)
		z_axe_cam_case(c);
	else
		x_y_z_axe_cam_case(c);
}

static void	init_cam(t_env *e)
{
	int	i;

	if (e->c)
		not_a_valid_file("multi cam setting is not handle\n");
	e->c = (t_cam *)malloc(sizeof(t_cam));
	e->c->pos = (float *)ft_memalloc(sizeof(float) * 3);
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
}

void	set_cam(char **tmp, t_env *e)
{
	char	***input;
	int	i;

	init_cam(e);
	i = input_number(tmp);
	input = (char ***)malloc(sizeof(char **) * i);
	i = 0;
	while (tmp[++i])
		input[i - 1] = ft_strsplit(tmp[i], ':');
	input[i - 1] = NULL;
	i = -1;
	while (input[++i])
	{
		if (!ft_strcmp("origin", input[i][0]))
			load_vect(e->c->pos, input[i][1]);
		else if (!ft_strcmp("direction", input[i][0]))
			load_vect(e->c->base[2], input[i][1]);
	}
	free_double_split(input);
	set_cam_base(e->c);
	set_cam_ray_dir(e->c);
}
