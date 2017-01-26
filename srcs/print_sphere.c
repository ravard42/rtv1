# include "rtv1.h"

void	print_sphere(float *c, float r, t_env *e, int color)
{
	int	i;
	float	param[3];

	i = -1;
	while (++i < MAX_X * MAX_Y)
	{
		param[0] = pow(e->dir[i][0], 2) + pow(e->dir[i][1], 2) + pow(e->dir[i][2], 2);
		param[1] = -2 * (e->dir[i][0] * c[0] + e->dir[i][1] * c[1] + e->dir[i][2] * c[2]);
		param[2] = pow(c[0], 2) + pow(c[1], 2) + pow(c[2], 2) - pow(r, 2);
		if (pow(param[1], 2) - 4 * param[0] * param[2] >= 0)
			*((unsigned int *)e->data_img + i) = color;
	}
}
