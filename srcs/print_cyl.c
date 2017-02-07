# include "rtv1.h"

void	print_cyl(float *origin, float *n, float *value)
{
	float	tmp[3][3];

	tmp[2][0] = 0;
	tmp[2][1] = 0;
	tmp[2][2] = 1;
	rot(n, value, tmp[2]);
	construct_transfer_mat(tmp);
	
}
