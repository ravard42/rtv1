# include "rtv1.h"

// dst et src peuvent overlap le resultat sera stock ds dst par contre src en sera modifiE

float	*matrix_product(float *dst, float **mat, float *src)
{
	float 	tmp[3];
	int	i;
	int	j;
	
	ft_memset(tmp, 0, sizeof(float) * 3);
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			tmp[i] += mat[j][i] * src[j];
	}
	i = -1;
	while (++i < 3)
		dst[i] = tmp[i];
	return (dst);
}

float	*matrix_sum(float *a, float *b)
{
	a[0] = a[0] + b[0];
	a[1] = a[1] + b[1];
	a[2] = a[2] + b[2];
	return (a);
}

float	*matrix_subtraction(float *a, float *b)
{
	a[0] = a[0] - b[0];
	a[1] = a[1] - b[1];
	a[2] = a[2] - b[2];
	return (a);
}
