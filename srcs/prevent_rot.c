# include "rtv1.h"

int	prevent_rot(int keycode, t_env *e)
{
	float	tmp[3];
	float	angle;

	tmp[0] = 0;
	tmp[1] = 0;
	tmp[2] = 1;
	if (keycode == BAS || keycode == BAS2)
	{
		angle = acos(scalar_product(tmp, e->c->base[2]));
		if (angle + ROT >= M_PI - M_PI / 17)
			return (1);
	}
	else if (keycode == HAUT || keycode == HAUT2)
	{
		angle = acos(scalar_product(tmp, e->c->base[2]));
		if (angle - ROT <= 0 + M_PI / 17)
			return (1);
	}
	return (0);
}
