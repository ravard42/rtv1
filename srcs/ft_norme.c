# include "rtv1.h"

void	ft_norme(float *v)
{
	float	tmp;

	if (v[0] == 0 && v[1] == 0 && v[2] == 0)
	{
		ft_putstr("on ne peut pas normer le vecteur NULL!\n");
		exit(0);
	}
	tmp = sqrt(pow(v[0], 2) + pow(v[1], 2) + pow(v[2], 2));
	v[0] = v[0] / tmp;
	v[1] = v[1] / tmp;
	v[2] = v[2] / tmp;
}
