# include "rtv1.h"

float	*set_vect(float *dst, float a, float b, float c)
{
	if (dst == NULL)
		dst = (float *)malloc(sizeof(float) * 3);
	dst[0] = a;
	dst[1] = b;
	dst[2] = c;
	return (dst);
}

float	*vectorial_copy(float *dst, float *src)
{
	dst[0] = src[0];
	dst[1] = src[1];
	dst[2] = src[2];
	return (dst);
}

