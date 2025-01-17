/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selecting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:37:07 by trazanad          #+#    #+#             */
/*   Updated: 2025/01/15 10:39:05 by trazanad         ###   ########.fr       */
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
	int r = rand()*255;  
	int b = rand()*255;  
	int g = rand()*255;
	int color = get_color_from_trgb(1,r, g, b);
	if ((*hit_pt)->shape->sphere)
	{
		(*hit_pt)->shape->sphere->color = color;
		scene->selected_obj->sphere = (*hit_pt)->shape->sphere;
		scene->selected_obj->cylinder = NULL;
		scene->selected_obj->plane = NULL;
		scene->select_camera = 0;
	}
	else if ((*hit_pt)->shape->cylinder)
	{
		(*hit_pt)->shape->cylinder->color = color;
		scene->selected_obj->cylinder = (*hit_pt)->shape->cylinder;
		scene->selected_obj->sphere = NULL;
		scene->selected_obj->plane = NULL;
		scene->select_camera = 0;
	}
	else if ((*hit_pt)->shape->plane)
	{
		(*hit_pt)->shape->plane->color = color;
		scene->selected_obj->plane = (*hit_pt)->shape->plane;
		scene->selected_obj->sphere = NULL;
		scene->selected_obj->cylinder = NULL;
		scene->select_camera = 0;
	}
}

