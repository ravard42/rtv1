# include "rtv1.h"

float	*hexa_to_rgb(float *rgb, int *hexa)
{
	rgb[0] = (float)*((unsigned char *)hexa + 2);
	rgb[1] = (float)*((unsigned char *)hexa + 1);
	rgb[2] = (float)*((unsigned char *)hexa);
	return (rgb);
}	

int	*rgb_to_hexa(int *hexa, float *rgb)
{

	*((unsigned char *)hexa + 2) = rgb[0];
	*((unsigned char *)hexa + 1) = rgb[1];
	*((unsigned char *)hexa) = rgb[2];
	return (hexa);
}

float	*rgb_to_coef(float *rgb)
{
	rgb[0] = rgb[0] / 255;
	rgb[1] = rgb[1] / 255;
	rgb[2] = rgb[2] / 255;
	return (rgb);
}

float	*coef_to_rgb(float *coef)
{
	coef[0] = coef[0] * 255;
	coef[1] = coef[1] * 255;
	coef[2] = coef[2] * 255;
	return (coef);
}

float	*light_bonus(float *rgb, char light)
{
	int	i;
	
	i = -1;
	while (++i < 3)
	{
		rgb[i] += 2 * light * rgb[i];
		rgb[i] = (rgb[i] > 255) ? 255 : rgb[i];
	}
	return (rgb);
}
