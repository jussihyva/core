#include "../inc/lin.h"

t_mat4	lin_m4_proj(double fov, double ratio, int near, int far)
{
	t_mat4	out;

	mem_zero(&out, sizeof(t_mat4));
	out.m[5] = 1 / tan(0.5 * fov * (CR_PI / 180));
	out.m[0] = out.m[5] / ratio;
	out.m[10] = -1 * (-near - far) / (near - far);
	out.m[11] = (2 * near * far) / (near - far);
	out.m[14] = -1;
	return (out);
}
