# include "rtv1.h"

// src et mp peuvent overlap le resultat sera stock ds mp par contre src en sera modifiE et vaudra mp UNIQUEMENT si les pointeur coincident au moment de l appel de la fonction sinon aucun soucis src restera tel quel! 

float	*matrix_product(float **mat, float *src, float *mp)
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
		mp[i] = tmp[i];
	return (mp);
}

float	*vectorial_sum(float *u, float *v, float *sum)
{
	sum[0] = u[0] + v[0];
	sum[1] = u[1] + v[1];
	sum[2] = u[2] + v[2];
	return (sum);
}

float	*vectorial_multi(int i, float *u)
{
	u[0] = i * u[0];
	u[1] = i * u[1];
	u[2] = i * u[2];
	return (u);
}
float	*vectorial_subtraction(float *u, float *v, float *sub)
{
	sub[0] = u[0] - v[0];
	sub[1] = u[1] - v[1];
	sub[2] = u[2] - v[2];
	return (sub);
}

float	*vectorial_product(float *u, float *v, float *prod)
{
	prod[0] = u[1] * v[2] - u[2] * v[1];
	prod[1] = u[2] * v[0] - u[0] * v[2];
	prod[2] = u[0] * v[1] - u[1] * v[0];
	return (prod);
}
