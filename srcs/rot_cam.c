# include "rtv1.h"

int	prevent_vertical_rot(int keycode, float **base)
{
	float	tmp[6];
	float	cos_angle;
	float	sin_angle;
	float	angle;

	if (base[2][0] == 0 && base[2][1] == 0)
	{
		tmp[0] = 1;
		tmp[1] = 0;
		tmp[2] = 0;
		tmp[3] = 0;
		tmp[4] = 1;
		tmp[5] = 0;
		cos_angle = scalar_product(tmp, base[0]);
		sin_angle = scalar_product(tmp + 3, base[0]);
		angle = (sin_angle >= 0) ? acos(cos_angle) : -acos(cos_angle);
		if (keycode == ROT_D || keycode == ROT_D2)
		{
			angle -= ROT;
			base[0][0] = cos(angle);
			base[0][1] = sin(angle);
			base[0][2] = 0;
		}
		else 		
		{
			angle += ROT;
			base[0][0] = cos(angle);
			base[0][1] = sin(angle);
			base[0][2] = 0;
		}
		vectorial_product(base[1], base[2], base[0]);		

		return (1);
	}
	return (0);
}


void	rot_d(float *eZcam)
{
	int	i;
	float	**rot_30;

	i = -1;
	rot_30 = (float **)malloc(sizeof(float *) * 3);	
	while (++i < 3)
		rot_30[i] = (float *)malloc(sizeof(float) * 3);	
	rot_30[0][0] = cos(ROT); 
	rot_30[0][1] = sin(-ROT);
	rot_30[0][2] = 0;
	rot_30[1][0] = sin(ROT);
	rot_30[1][1] = cos(ROT);
	rot_30[1][2] = 0;
	rot_30[2][0] = 0;
	rot_30[2][1] = 0;
	rot_30[2][2] = 1;
	matrix_product(eZcam, rot_30, eZcam);
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
	rot_30[0][0] = cos(ROT); 
	rot_30[0][1] = sin(ROT);
	rot_30[0][2] = 0;
	rot_30[1][0] = sin(-ROT);
	rot_30[1][1] = cos(ROT);
	rot_30[1][2] = 0;
	rot_30[2][0] = 0;
	rot_30[2][1] = 0;
	rot_30[2][2] = 1;
	matrix_product(eZcam, rot_30, eZcam);
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
	rot_30[0][0] = cos(ROT)  + (1 - cos(ROT)) * (pow(base[0][0], 2)); 
	rot_30[0][1] = (1 - cos(ROT)) * (base[0][0] * base[0][1]) + sin(ROT) * (-base[0][2]);
	rot_30[0][2] = (1 - cos(ROT)) * (base[0][0] * base[0][2]) + sin(ROT) * (base[0][1]);
	rot_30[1][0] = (1 - cos(ROT)) * (base[0][0] * base[0][1]) + sin(ROT) * (base[0][2]);
	rot_30[1][1] = cos(ROT) + (1 - cos(ROT)) * (pow(base[0][1], 2));
	rot_30[1][2] = (1 - cos(ROT)) * (base[0][1] * base[0][2]) + sin(ROT) * (-base[0][0]);
	rot_30[2][0] = (1 - cos(ROT)) * (base[0][0] * base[0][2]) + sin(ROT) * (-base[0][1]);
	rot_30[2][1] = (1 - cos(ROT)) * (base[0][1] * base[0][2]) + sin(ROT) * (base[0][0]);
	rot_30[2][2] = cos(ROT) + (1 - cos(ROT)) * (pow(base[0][2], 2));
	matrix_product(base[2], rot_30, base[2]);
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
	rot_30[0][0] = cos(ROT)  + (1 - cos(ROT)) * (pow(base[0][0], 2)); 
	rot_30[0][1] = (1 - cos(ROT)) * (base[0][0] * base[0][1]) - sin(ROT) * (-base[0][2]);
	rot_30[0][2] = (1 - cos(ROT)) * (base[0][0] * base[0][2]) - sin(ROT) * (base[0][1]);
	rot_30[1][0] = (1 - cos(ROT)) * (base[0][0] * base[0][1]) - sin(ROT) * (base[0][2]);
	rot_30[1][1] = cos(ROT) + (1 - cos(ROT)) * (pow(base[0][1], 2));
	rot_30[1][2] = (1 - cos(ROT)) * (base[0][1] * base[0][2]) - sin(ROT) * (-base[0][0]);
	rot_30[2][0] = (1 - cos(ROT)) * (base[0][0] * base[0][2]) - sin(ROT) * (-base[0][1]);
	rot_30[2][1] = (1 - cos(ROT)) * (base[0][1] * base[0][2]) - sin(ROT) * (base[0][0]);
	rot_30[2][2] = cos(ROT) + (1 - cos(ROT)) * (pow(base[0][2], 2));
	matrix_product(base[2], rot_30,  base[2]);
	i = -1;
	while (++i < 3)
		free(rot_30[i]);
	free(rot_30);
	
}
