# include "rtv1.h"

float	det(float **mat)
{
	return (mat[0][0] * mat[1][1] * mat[2][2]
		- mat[0][0] * mat[1][2] * mat[2][1]
		- mat[0][1] * mat[1][0] * mat[2][2]
		+ mat[0][1] * mat[1][2] * mat[2][0]
		- mat[0][2] * mat[1][1] * mat[2][0]
		+ mat[0][2] * mat[1][0] * mat[2][1]);
}

float	**transpose(float **mat)
{
	float	tmp[3][3];
	int	i;
	int	j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			tmp[i][j] = mat[i][j];
	}
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			mat[i][j] = tmp[j][i];
	}
	return (mat);
}

float 	**inverse(float **mat)
{
	float	tmp[3][3];
	int	i;
	int	j;
	float	k;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			tmp[i][j] = mat[i][j];
	}
	k = 1 / det(mat);
	mat[0][0] = k * (tmp[1][1] * tmp[2][2] - tmp[1][2] * tmp[2][1]);
	mat[0][1] = -k * (tmp[1][0] * tmp[2][2] - tmp[1][2] * tmp[2][0]);
	mat[0][2] = k * (tmp[1][0] * tmp[2][1] - tmp[1][1] * tmp[2][0]);
	mat[1][0] = -k * (tmp[0][1] * tmp[2][2] - tmp[2][1] * tmp[0][2]);
	mat[1][1] = k * (tmp[0][0] * tmp[2][2] - tmp[2][0] * tmp[0][2]);
	mat[1][2] = -k * (tmp[0][0] * tmp[2][1] - tmp[0][1] * tmp[2][0]);
	mat[2][0] = k * (tmp[0][1] * tmp[1][2] - tmp[0][2] * tmp[1][1]);
	mat[2][1] = -k * (tmp[0][0] * tmp[1][2] - tmp[0][2] * tmp[1][0]);
	mat[2][2] = k * (tmp[0][0] * tmp[1][1] - tmp[0][1] * tmp[1][0]);
	return (transpose(mat));
}
