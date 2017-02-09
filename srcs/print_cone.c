# include "rtv1.h"

void	print_cone(float *origin, float *a, float *n, float value, t_env *e, int color)
{
	float	**mat;
	int	i;
	float	new_cam[3];
	float	**new_dir;

	mat = (float **)malloc(sizeof(float *) * 3);
	i = -1;
	while (++i < 3)
		mat[i] = (float *)malloc(sizeof(float) * 3);
	mat[2][0] = 0;
	mat[2][1] = 0;
	mat[2][2] = 1;
	rot(n, value, mat[2]);
	construct_transfer_mat(mat);
	inverse(mat);
	matrix_product(mat, origin, origin);
	matrix_product(mat, e->s->cam, new_cam);
	new_dir = (float **)malloc(sizeof(float *) * MAX_X * MAX_Y);
	i = -1;
	while (++i < MAX_X * MAX_Y)
	{
		new_dir[i] = (float *)malloc(sizeof(float) * 3);
		matrix_product(mat, e->s->dir[i] , new_dir[i]);
	}

	
	float	param[3];
	float	delt;
	float	tmp;
	float	sol[3];
	
	i = -1;
	while (++i < MAX_X * MAX_Y)
	{
		tmp = e->s->dist[i];
		param[0] = pow(new_dir[i][0], 2) / a[0] + pow(new_dir[i][1], 2) / a[1] - pow(new_dir[i][2], 2) / a[2];
		param[1] = 2 * (new_dir[i][0] * (new_cam[0] - origin[0]) / a[0] + new_dir[i][1] * (new_cam[1] - origin[1]) / a[1] - new_dir[i][2] * (new_cam[2] - origin[2]) / a[2]);
		param[2] = pow(new_cam[0] - origin[0], 2) / a[0] + pow(new_cam[1] - origin[1], 2) / a[1] - pow(new_cam[2] - origin[2], 2) / a[2];
		if ((delt = pow(param[1], 2) - 4 * param[0] * param[2]) == 0)
		{
			sol[0] = -param[1] / (2 * param[0]);
			e->s->dist[i] = (sol[0] > VP_DIST  && e->s->dist[i] > sol[0]) ? sol[0] : e->s->dist[i];
		}
		else if (delt > 0)
		{
			sol[0] = (-param[1] + sqrt(delt))/ (2 * param[0]);
			sol[1] = (-param[1] - sqrt(delt))/ (2 * param[0]);
			if ((sol[0] <= VP_DIST && sol[1] > VP_DIST) || (sol[0] > VP_DIST && sol[1] <= VP_DIST))
			{
				sol[2] = (sol[0] > VP_DIST) ? sol[0] : sol[1];
				e->s->dist[i] = (e->s->dist[i] > sol[2]) ? sol[2] : e->s->dist[i];
			}
			else if (sol[0] > VP_DIST && sol[1] > VP_DIST)	
			{
				sol[2] = (sol[0] <= sol[1]) ? sol[0] : sol[1];
				e->s->dist[i] = (e->s->dist[i] > sol[2]) ? sol[2] : e->s->dist[i];
			}
		}
		if (tmp != e->s->dist[i])
			*((unsigned int *)e->data_img + i) = color;
	}
}
