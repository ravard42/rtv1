# include "rtv1.h"

void	init_transfer_stuff(t_env *e)
{
	int	i;

	e->t = (t_trsf *)malloc(sizeof(t_trsf));
	e->t->mat = (float **)malloc(sizeof(float *) * 3);
	i = -1;
	while (++i < 3)
		e->t->mat[i] = (float *)malloc(sizeof(float) * 3);
	e->t->cam_pos = (float *)malloc(sizeof(float) * 3);
	e->t->obj_pos = (float *)malloc(sizeof(float) * 3);
	e->t->cam_r_dir = (float **)malloc(sizeof(float *) * MAX_X * MAX_Y);
	i = -1;
	while (++i < MAX_X * MAX_Y)
		e->t->cam_r_dir[i] = (float *)malloc(sizeof(float) * 3);
}

// on effectue la rotation de eZ de value radian par rapport a n et on stock le resultat dans eZ

void	rot(float *eZ, float value, float *n)
{
	int	i;
	float	**rot;

	
	ft_norme(n);
	rot = (float **)malloc(sizeof(float *) * 3);	
	i = -1;
	while (++i < 3)
		rot[i] = (float *)malloc(sizeof(float) * 3);	
	rot[0][0] = cos(value)  + (1 - cos(value)) * (pow(n[0], 2)); 
	rot[0][1] = (1 - cos(value)) * (n[0] * n[1]) - sin(value) * (-n[2]);
	rot[0][2] = (1 - cos(value)) * (n[0] * n[2]) - sin(value) * (n[1]);
	rot[1][0] = (1 - cos(value)) * (n[0] * n[1]) - sin(value) * (n[2]);
	rot[1][1] = cos(value) + (1 - cos(value)) * (pow(n[1], 2));
	rot[1][2] = (1 - cos(value)) * (n[1] * n[2]) - sin(value) * (-n[0]);
	rot[2][0] = (1 - cos(value)) * (n[0] * n[2]) - sin(value) * (-n[1]);
	rot[2][1] = (1 - cos(value)) * (n[1] * n[2]) - sin(value) * (n[0]);
	rot[2][2] = cos(value) + (1 - cos(value)) * (pow(n[2], 2));
	matrix_product(eZ, rot, eZ);
	i = -1;
	while (++i < 3)
		free(rot[i]);
	free(rot);
}

void	construct_transfer_mat(float **base)
{
	int		sens;

	ft_norme(base[2]);
	if (base[2][1] == 0 && base[2][2] == 0)
	{
		sens = (base[2][0] > 0) ? 1 : -1;
		base[0][0] = 0;
		base[0][1] = -sens;
		base[0][2] = 0;
		base[1][0] = 0;
		base[1][1] = 0;
		base[1][2] = -1;
	}
	else if (base[2][0] == 0 && base[2][2] == 0)
	{
		sens = (base[2][1] > 0) ? 1 : -1;
		base[0][0] = sens;
		base[0][1] = 0;
		base[0][2] = 0;
		base[1][0] = 0;
		base[1][1] = 0;
		base[1][2] = -1;
	}
	else if (base[2][0] == 0 && base[2][1] == 0)
	{
		sens = (base[2][2] > 0) ? 1 : -1;
		base[0][0] = 0;
		base[0][1] = 1;
		base[0][2] = 0;
		base[1][0] = -sens;
		base[1][1] = 0;
		base[1][2] = 0;
	}
	else if (base[2][0] == 0)
	{
		sens = (base[2][1] > 0) ? 1 : -1;
		base[0][0] = sens;
		base[0][1] = 0;
		base[0][2] = 0;
		base[1][0] = 0;
		base[1][1] = base[2][2] * sens;
		base[1][2] = -base[2][1] * sens;
	}
	else if (base[2][1] == 0)
	{
		sens = (base[2][0] > 0) ? 1 : -1;
		base[0][0] = 0;
		base[0][1] = -sens;
		base[0][2] = 0;
		base[1][0] = base[2][2] * sens;
		base[1][1] = 0;
		base[1][2] = -base[2][0] * sens;
	}
	else
	{
		sens = (base[2][0] * base[2][1] > 0) ? 1 : -1;
		base[0][0] = sens / base[2][0];
		base[0][1] = -sens / base[2][1];
		base[0][2] = 0;
		ft_norme(base[0]);
		vectorial_product(base[1], base[2], base[0]);
	}
}

void		set_transfer_stuff(float rot_val, float *axe_rot, float *obj_pos, t_env *e)
{
	int	i;
	
	e->t->mat[2][0] = 0;
	e->t->mat[2][1] = 0;
	e->t->mat[2][2] = 1;
	rot(e->t->mat[2], rot_val, axe_rot);
	construct_transfer_mat(e->t->mat);
	inverse(e->t->mat);
	matrix_product(e->t->cam_pos, e->t->mat, e->c->pos);
	matrix_product(e->t->obj_pos, e->t->mat, obj_pos);
	i = -1;
	while (++i < MAX_X * MAX_Y)
		matrix_product(e->t->cam_r_dir[i], e->t->mat, e->c->r_dir[i]);
}
