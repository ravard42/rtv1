# include "rtv1.h"

void	set_dir(t_env *e)
{
	int	i;
	float	norme;
	float	tmp[3];

	i = -1;
	while (++i < MAX_X * MAX_Y)
	{
		norme = sqrt(pow(-1 * VP_WIDTH / 2 + i % MAX_X * VP_WIDTH / MAX_X, 2) + pow(-1 * VP_HEIGHT / 2 + i / MAX_Y * VP_HEIGHT / MAX_Y, 2) + pow(VP_DIST, 2));
		tmp[0] = (-1 * VP_WIDTH / 2 + i % MAX_X * VP_WIDTH / MAX_X) / norme;
		tmp[1] = (-1 * VP_HEIGHT / 2 + i / MAX_Y * VP_HEIGHT / MAX_Y) / norme;
		tmp[2] = VP_DIST / norme;
		matrix_product(e->s->dir[i], e->s->base, tmp);
	}
	clear_img_dist(e);
}
