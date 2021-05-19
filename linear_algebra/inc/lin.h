/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Functions for linear algebra.
 *
 *****************************************************************************/

#ifndef LIN_H
# define LIN_H
# include "../../inc/types.h"

double			lin_v4_dot(t_vec4 *a, t_vec4 *b);
t_vec4			lin_v4_sub(t_vec4 *a, t_vec4 *b);
t_vec4			lin_v4_cross(t_vec4 *a, t_vec4 *b);
t_vec4			lin_v4_norm(t_vec4 *src);
double			lin_v4_mag(t_vec4 *src);
t_mat4			lin_m4_id(void);
t_mat4			lin_m4_rotx(double angle);
t_mat4			lin_m4_roty(double angle);
t_mat4			lin_m4_rotz(double angle);
t_mat4			lin_m4_proj(double fov, double ratio, int near, int far);
t_mat4			lin_m4_transform(double scale);
t_mat4			lin_m4_translate(t_vec4 *src);
t_vec4			lin_m4_getcol(t_mat4 *src, uint8_t col);
t_vec4			lin_m4_getrow(t_mat4 *src, uint8_t row);
void			lin_m4_print(const t_mat4 *src);
t_mat4			lin_m4xm4_r(t_mat4 *a, t_mat4 *b);
t_vec4			lin_m4xv4_r(t_mat4 *a, t_vec4 *b);
ssize_t			lin_v4_print(void *elem, size_t i);

#endif
