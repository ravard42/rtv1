# include "rtv1.h"

void	rot_d(float *eZcam)
{
	int	i;
	float	**rot_30;

	i = -1;
	rot_30 = (float **)malloc(sizeof(float *) * 3);	
	while (++i < 3)
		rot_30[i] = (float *)malloc(sizeof(float) * 3);	
	rot_30[0][0] = cos(M_PI / 6); 
	rot_30[0][1] = sin(-M_PI / 6);
	rot_30[0][2] = 0;
	rot_30[1][0] = sin(M_PI / 6);
	rot_30[1][1] = cos(M_PI / 6);
	rot_30[1][2] = 0;
	rot_30[2][0] = 0;
	rot_30[2][1] = 0;
	rot_30[2][2] = 1;
	matrix_product(rot_30, eZcam, eZcam);
	i = -1;
	while (++i < 3)
		free(rot_30[i]);
	free(rot_30);
}

void	rot_g(float *eZcam)
{
	int	i;
	float	**rot_30;

	i = -1;
	rot_30 = (float **)malloc(sizeof(float *) * 3);	
	while (++i < 3)
		rot_30[i] = (float *)malloc(sizeof(float) * 3);	
	rot_30[0][0] = cos(M_PI / 6); 
	rot_30[0][1] = sin(M_PI / 6);
	rot_30[0][2] = 0;
	rot_30[1][0] = sin(-M_PI / 6);
	rot_30[1][1] = cos(M_PI / 6);
	rot_30[1][2] = 0;
	rot_30[2][0] = 0;
	rot_30[2][1] = 0;
	rot_30[2][2] = 1;
	matrix_product(rot_30, eZcam, eZcam);
	i = -1;
	while (++i < 3)
		free(rot_30[i]);
	free(rot_30);
}


void	rot_b(float **base)
{
	int	i;
	float	**rot_30;

	i = -1;
	rot_30 = (float **)malloc(sizeof(float *) * 3);	
	while (++i < 3)
		rot_30[i] = (float *)malloc(sizeof(float) * 3);	
	rot_30[0][0] = cos(M_PI / 6)  + (1 - cos(M_PI / 6)) * (pow(base[0][0], 2)); 
	rot_30[0][1] = (1 - cos(M_PI / 6)) * (base[0][0] * base[0][1]) + sin(M_PI / 6) * (-base[0][2]);
	rot_30[0][2] = (1 - cos(M_PI / 6)) * (base[0][0] * base[0][2]) + sin(M_PI / 6) * (base[0][1]);
	rot_30[1][0] = (1 - cos(M_PI / 6)) * (base[0][0] * base[0][1]) + sin(M_PI / 6) * (base[0][2]);
	rot_30[1][1] = cos(M_PI / 6) + (1 - cos(M_PI / 6)) * (pow(base[0][1], 2));
	rot_30[1][2] = (1 - cos(M_PI / 6)) * (base[0][1] * base[0][2]) + sin(M_PI / 6) * (-base[0][0]);
	rot_30[2][0] = (1 - cos(M_PI / 6)) * (base[0][0] * base[0][2]) + sin(M_PI / 6) * (-base[0][1]);
	rot_30[2][1] = (1 - cos(M_PI / 6)) * (base[0][1] * base[0][2]) + sin(M_PI / 6) * (base[0][0]);
	rot_30[2][2] = cos(M_PI / 6) + (1 - cos(M_PI / 6)) * (pow(base[0][2], 2));
	matrix_product(rot_30, base[2], base[2]);
	i = -1;
	while (++i < 3)
		free(rot_30[i]);
	free(rot_30);
	
}

void	rot_h(float **base)
{
	int	i;
	float	**rot_30;

	i = -1;
	rot_30 = (float **)malloc(sizeof(float *) * 3);	
	while (++i < 3)
		rot_30[i] = (float *)malloc(sizeof(float) * 3);	
	rot_30[0][0] = cos(M_PI / 6)  + (1 - cos(M_PI / 6)) * (pow(base[0][0], 2)); 
	rot_30[0][1] = (1 - cos(M_PI / 6)) * (base[0][0] * base[0][1]) - sin(M_PI / 6) * (-base[0][2]);
	rot_30[0][2] = (1 - cos(M_PI / 6)) * (base[0][0] * base[0][2]) - sin(M_PI / 6) * (base[0][1]);
	rot_30[1][0] = (1 - cos(M_PI / 6)) * (base[0][0] * base[0][1]) - sin(M_PI / 6) * (base[0][2]);
	rot_30[1][1] = cos(M_PI / 6) + (1 - cos(M_PI / 6)) * (pow(base[0][1], 2));
	rot_30[1][2] = (1 - cos(M_PI / 6)) * (base[0][1] * base[0][2]) - sin(M_PI / 6) * (-base[0][0]);
	rot_30[2][0] = (1 - cos(M_PI / 6)) * (base[0][0] * base[0][2]) - sin(M_PI / 6) * (-base[0][1]);
	rot_30[2][1] = (1 - cos(M_PI / 6)) * (base[0][1] * base[0][2]) - sin(M_PI / 6) * (base[0][0]);
	rot_30[2][2] = cos(M_PI / 6) + (1 - cos(M_PI / 6)) * (pow(base[0][2], 2));
	matrix_product(rot_30, base[2], base[2]);
	i = -1;
	while (++i < 3)
		free(rot_30[i]);
	free(rot_30);
	
}
