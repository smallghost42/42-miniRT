/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:10:08 by trazanad          #+#    #+#             */
/*   Updated: 2025/01/14 16:01:59 by trazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float   to_rad_angle(float angle)
{
    float rad_angle;

    rad_angle = angle * PI / 180;
    return (rad_angle);
}

t_vec3  rotate_x(t_vec3 u, float angle)
{
    t_vec3  v;
    float   theta;
    
    theta = to_rad_angle(angle);
    v.x = u.x;
    v.y = u.y * cos(theta) - u.z * sin(theta);
    v.z = u.y * sin(theta) + u.z * cos(theta);
    return (v);
}

t_vec3  rotate_y(t_vec3 u, float angle)
{
    t_vec3  v;
    float   theta;
    
    theta = to_rad_angle(angle);
    v.y = u.y;
    v.x = u.x * cos(theta) + u.z * sin(theta);
    v.z = u.x * -sin(theta) + u.z * cos(theta);
    return (v);
}

t_vec3  rotate_z(t_vec3 u, float angle)
{
    t_vec3  v;
    float   theta;
    
    theta = to_rad_angle(angle);
    v.z = u.z;
    v.x = u.x * cos(theta) - u.y * sin(theta);
    v.y = u.x * sin(theta) + u.y * cos(theta);
    return (v);
}

t_vec3  translate_x(t_vec3  u, float k)
{
    return (vec3_create(u.x + k, u.y, u.z));    
}

t_vec3  translate_y(t_vec3  u, float k)
{
    return (vec3_create(u.x, u.y + k, u.z));    
}

t_vec3  translate_z(t_vec3  u, float k)
{
    return (vec3_create(u.x, u.y, u.z + k));    
}
