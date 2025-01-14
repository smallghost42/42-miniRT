/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selecting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:37:07 by trazanad          #+#    #+#             */
/*   Updated: 2025/01/14 09:46:42 by trazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	select_object(int x, int y, t_scene *scene)
{
	int		coord[2];
	t_ray	ray;
	t_hit_pt	**hit_pt;

	coord[0] = x;
	coord[1] = y;
	ray = visibility_ray(scene->data, coord);
	hit_pt = &(scene->hit_pt);
	get_object_distance(scene->data, ray, &((*hit_pt)->shape));
	if (!(*hit_pt)->shape)
		return ;
	// print_shape((*hit_pt)->shape);
	if ((*hit_pt)->shape->plane)
		print_plane((*hit_pt)->shape->plane);
	if ((*hit_pt)->shape->sphere)
		print_sphere((*hit_pt)->shape->sphere);
	if ((*hit_pt)->shape->cylinder)
		print_cylinder((*hit_pt)->shape->cylinder);
	if ((*hit_pt)->shape->cylinder)
		(*hit_pt)->shape->cylinder->color = 255;
	else if ((*hit_pt)->shape->sphere)
		(*hit_pt)->shape->sphere->color = 255;
	else if ((*hit_pt)->shape->plane)
		(*hit_pt)->shape->plane->color = 255;
}

// void	update_data(t_data **data, t_hit_pt **hit_pt)
// {
// 	t_camera*	camera;
// 	t_shape*	shape;

// 	shape = (*hit_pt)->shape;
// 	camera = (*data)->camera;
// 	if (!shape)
// 		return ;
// }
