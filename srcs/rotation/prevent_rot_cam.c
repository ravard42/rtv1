# include "rtv1.h"

int	prevent_hori_rot(int keycode, float **base)
{
	float	tmp[6];
	float	cos_angle;
	float	sin_angle;
	float	angle;

	if (base[2][0] == 0 && base[2][1] == 0)
	{
		set_vect(tmp, 1, 0, 0);
		set_vect(tmp + 3, 0, 1, 0);
		cos_angle = scalar_product(tmp, base[0]);
		sin_angle = scalar_product(tmp + 3, base[0]);
		angle = (sin_angle >= 0) ? acos(cos_angle) : -acos(cos_angle);
		if (keycode == ROT_D || keycode == ROT_D2)
			set_vect(base[0], cos(angle - ROT), sin(angle - ROT), 0);
		else 		
			set_vect(base[0], cos(angle + ROT), sin(angle + ROT), 0);
		vectorial_product(base[1], base[2], base[0]);		
		return (1);
	}
	return (0);
}

int	prevent_vert_rot(int keycode, t_env *e)
{
	float	tmp[3];
	float	angle;

	set_vect(tmp, 0, 0, 1);
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
