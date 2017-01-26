# include "rtv1.h"

float	**set_dir()
{
	float	**dir;
	int	i;
	float	norme;

	dir = (float **)malloc(sizeof(float *) * MAX_X * MAX_Y);
	i = -1;
	while (++i < MAX_X * MAX_Y)
		dir[i] = (float *)malloc(sizeof(float) * 3);
	i = -1;
	while (++i < MAX_X * MAX_Y)
	{
		norme = sqrt(pow(-1 * VP_WIDTH / 2 + i % MAX_X * VP_WIDTH / MAX_X, 2) + pow(-1 * VP_HEIGHT / 2 + i / MAX_Y * VP_HEIGHT / MAX_Y, 2) + pow(VP_DIST, 2));
		dir[i][0] = (-1 * VP_WIDTH / 2 + i % MAX_X * VP_WIDTH / MAX_X) / norme;
		dir[i][1] = (-1 * VP_HEIGHT / 2 + i / MAX_Y * VP_HEIGHT / MAX_Y) / norme;
		dir[i][2] = VP_DIST / norme;		
	}
	return (dir);
}
