/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Functions for linear algebra.
 *
 *****************************************************************************/

#ifndef LIN_H
# define LIN_H
# include "../../inc/core.h"

typedef struct s_vec4
{
	double		v[4];
}				t_vec4;

typedef struct s_vec3
{
	double		v[3];
}				t_vec3;

typedef struct s_vec2
{
	double		v[2];
}				t_vec2;

typedef struct	s_mat
{
	double		*m;
	size_t		x;
	size_t		y;
}				t_mat;

typedef struct s_mat4
{
	double		m[16];
}				t_mat4;

typedef struct s_mat3
{
	double		m[9];
}				t_mat3;

typedef struct s_mat2
{
	double		m[4];
}				t_mat2;

typedef t_vec4	t_quat;

/*
**-----------------------------------------------------------------------------
**	VEC4
*/
double			lin_v4_dot(t_vec4 *a, t_vec4 *b);
t_vec4			lin_v4_sub(t_vec4 *a, t_vec4 *b);
t_vec4			lin_v4_cross(t_vec4 *a, t_vec4 *b);
t_vec4			lin_v4_norm(t_vec4 *src);
double			lin_v4_mag(t_vec4 *src);
/*
**-----------------------------------------------------------------------------
**	MTX4
*/
t_mat4			lin_m4_id(void);
t_mat4			lin_m4_rotx(double angle);
t_mat4			lin_m4_roty(double angle);
t_mat4			lin_m4_rotz(double angle);
t_mat4			lin_m4_proj(double fov, double ratio, int near, int far);
t_mat4			lin_m4_transform(double scale);
t_mat4			lin_m4_translate(t_vec4 *src);
t_vec4			lin_m4_getcol(t_mat4 *src, uint8_t col);
t_vec4			lin_m4_getrow(t_mat4 *src, uint8_t row);
/*
**-----------------------------------------------------------------------------
**	Multiplications
*/
void			lin_m4_print(const t_mat4 *src);
t_mat4			lin_m4xm4_r(t_mat4 *a, t_mat4 *b);
t_vec4			lin_m4xv4_r(t_mat4 *a, t_vec4 *b);
/*
**-----------------------------------------------------------------------------
**	Print
*/
ssize_t			lin_v4_print(void *elem, size_t i);
#endif
