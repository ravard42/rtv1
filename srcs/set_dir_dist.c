# include "rtv1.h"

void	set_dir_dist(t_env *e)
{
	int	i;
	float	norme;

	e->dir = (float **)malloc(sizeof(float *) * MAX_X * MAX_Y);
	i = -1;
	while (++i < MAX_X * MAX_Y)
		e->dir[i] = (float *)malloc(sizeof(float) * 3);
	i = -1;
	while (++i < MAX_X * MAX_Y)
	{
		norme = sqrt(pow(-1 * VP_WIDTH / 2 + i % MAX_X * VP_WIDTH / MAX_X, 2) + pow(-1 * VP_HEIGHT / 2 + i / MAX_Y * VP_HEIGHT / MAX_Y, 2) + pow(VP_DIST, 2));
		e->dir[i][0] = (-1 * VP_WIDTH / 2 + i % MAX_X * VP_WIDTH / MAX_X) / norme;
		e->dir[i][1] = (-1 * VP_HEIGHT / 2 + i / MAX_Y * VP_HEIGHT / MAX_Y) / norme;
		e->dir[i][2] = VP_DIST / norme;		
	}
	e->dist = (float *)malloc(sizeof(float) * MAX_X * MAX_Y);
	i = -1;
	while (++i < MAX_X * MAX_Y)
		e->dist[i] = MAX_DIST_PERCEPTION;	
}
