# include "rtv1.h"

float	*matrix_product(float *mp, float **mat, float *src)
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
