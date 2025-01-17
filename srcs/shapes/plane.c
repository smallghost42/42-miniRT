/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:22:35 by trazanad          #+#    #+#             */
/*   Updated: 2025/01/14 14:44:58 by trazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	plane_ray_hit_distance(t_ray ray, t_vec3 plane_pt, t_vec3 plane_normal)
{
	float	distance;
	float	denom;
	t_vec3	camera_to_point;

	camera_to_point = vec3_substract(plane_pt, ray.origin);
	distance = vec3_dot_product(plane_normal, camera_to_point);
	denom = vec3_dot_product(plane_normal, ray.direction);
	if (fabs(denom) < 1e-6)
		return (-1);
    distance /= denom;
	return (distance);
}

