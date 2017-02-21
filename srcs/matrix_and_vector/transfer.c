# include "rtv1.h"

static void	z_axe_case(float **base)
{
	int		sens;

	sens = (base[2][2] > 0) ? 1 : -1;
	set_vect(base[0], 0, 1, 0);
	set_vect(base[1], -sens, 0, 0);
}

static void	x_y_z_axe_case(float **base)
{
	int		sens;

	if (base[2][0] == 0)
	{
		sens = (base[2][1] > 0) ? 1 : -1;
		set_vect(base[0], sens, 0, 0);
	}
	else if (base[2][1] == 0)
	{
		sens = (base[2][0] > 0) ? -1 : 1;
		set_vect(base[0], 0, sens, 0);
	}
	else
	{
		sens = (base[2][0] * base[2][1] > 0) ? 1 : -1;
		set_vect(base[0], sens / base[2][0],
				-sens / base[2][1], 0);
	}
	ft_norme(base[0]);
	vectorial_product(base[1], base[2], base[0]);
}

void	construct_transfer_mat(float **base)
{
	ft_norme(base[2]);
	if (base[2][0] == 0 && base[2][1] == 0)
		z_axe_case(base);
	else
		x_y_z_axe_case(base);
}

void	set_cyl_transfer(t_cyl *cy)
{
	int	i;

	cy->t = (t_trsf *)malloc(sizeof(t_trsf));
	cy->t->mat = (float **)malloc(sizeof(float *) * 3);
	i = -1;
	while (++i < 3)
		cy->t->mat[i] = (float *)malloc(sizeof(float) * 3);
	cy->t->cam_pos = (float *)malloc(sizeof(float) * 3);
	cy->t->obj_pos = (float *)malloc(sizeof(float) * 3);
	cy->t->cam_r_dir = (float **)malloc(sizeof(float *) * MAX_X * MAX_Y);
	i = -1;
	while (++i < MAX_X * MAX_Y)
		cy->t->cam_r_dir[i] = (float *)malloc(sizeof(float) * 3);
	vectorial_copy(cy->t->mat[2], cy->axe);	
	construct_transfer_mat(cy->t->mat);
	inverse(cy->t->mat);
}

void	set_cone_transfer(t_con *co)
{
	int	i;

	co->t = (t_trsf *)malloc(sizeof(t_trsf));
	co->t->mat = (float **)malloc(sizeof(float *) * 3);
	i = -1;
	while (++i < 3)
		co->t->mat[i] = (float *)malloc(sizeof(float) * 3);
	co->t->cam_pos = (float *)malloc(sizeof(float) * 3);
	co->t->obj_pos = (float *)malloc(sizeof(float) * 3);
	co->t->cam_r_dir = (float **)malloc(sizeof(float *) * MAX_X * MAX_Y);
	i = -1;
	while (++i < MAX_X * MAX_Y)
		co->t->cam_r_dir[i] = (float *)malloc(sizeof(float) * 3);
	vectorial_copy(co->t->mat[2], co->axe);
	construct_transfer_mat(co->t->mat);
	inverse(co->t->mat);
}
