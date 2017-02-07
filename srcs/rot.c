# include "rtv1.h"

void	rot(float *n, float *value, float *eZ)
{
	int	i;
	float	**rot;

	i = -1;
	rot = (float **)malloc(sizeof(float *) * 3);	
	while (++i < 3)
		rot[i] = (float *)malloc(sizeof(float) * 3);	
	rot[0][0] = cos(value)  + (1 - cos(value)) * (pow(n[0], 2)); 
	rot[0][1] = (1 - cos(value)) * (n[0] * n[1]) - sin(value) * (-n[2]);
	rot[0][2] = (1 - cos(value)) * (n[0] * n[2]) - sin(value) * (n[1]);
	rot[1][0] = (1 - cos(value)) * (n[0] * n[1]) - sin(value) * (n[2]);
	rot[1][1] = cos(value) + (1 - cos(value)) * (pow(n[1], 2));
	rot[1][2] = (1 - cos(value)) * (n[1] * n[2]) - sin(value) * (-n[0]);
	rot[2][0] = (1 - cos(value)) * (n[0] * n[2]) - sin(value) * (-n[1]);
	rot[2][1] = (1 - cos(value)) * (n[1] * n[2]) - sin(value) * (n[0]);
	rot[2][2] = cos(value) + (1 - cos(value)) * (pow(n[2], 2));
	matrix_product(rot, eZ, eZ);
	i = -1;
	while (++i < 3)
		free(rot[i]);
	free(rot);
}

void	construct_transfer_mat(float **base)
{
	int		sens;

	ft_norme(base[2]);
	if (base[2][1] == 0 && base[2][2] == 0)
	{
		sens = (base[2][0] > 0) ? 1 : -1;
		base[0][0] = 0;
		base[0][1] = -sens;
		base[0][2] = 0;
		base[1][0] = 0;
		base[1][1] = 0;
		base[1][2] = -1;
	}
	else if (base[2][0] == 0 && base[2][2] == 0)
	{
		sens = (base[2][1] > 0) ? 1 : -1;
		base[0][0] = sens;
		base[0][1] = 0;
		base[0][2] = 0;
		base[1][0] = 0;
		base[1][1] = 0;
		base[1][2] = -1;
	}
	else if (base[2][0] == 0 && base[2][1] == 0)
	{
		sens = (base[2][2] > 0) ? 1 : -1;
		base[0][0] = 0;
		base[0][1] = 1;
		base[0][2] = 0;
		base[1][0] = -sens;
		base[1][1] = 0;
		base[1][2] = 0;
	}
	else if (base[2][0] == 0)
	{
		sens = (base[2][1] > 0) ? 1 : -1;
		base[0][0] = sens;
		base[0][1] = 0;
		base[0][2] = 0;
		base[1][0] = 0;
		base[1][1] = base[2][2] * sens;
		base[1][2] = -base[2][1] * sens;
	}
	else if (base[2][1] == 0)
	{
		sens = (base[2][0] > 0) ? 1 : -1;
		base[0][0] = 0;
		base[0][1] = -sens;
		base[0][2] = 0;
		base[1][0] = base[2][2] * sens;
		base[1][1] = 0;
		base[1][2] = -base[2][0] * sens;
	}
	else
	{
		sens = (base[2][0] * base[2][1] > 0) ? 1 : -1;
		base[0][0] = sens / base[2][0];
		base[0][1] = -sens / base[2][1];
		base[0][2] = 0;
		ft_norme(base[0]);
		vectorial_product(base[2], base[0], base[1]);
	}
}
