/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:40:30 by trazanad          #+#    #+#             */
/*   Updated: 2025/01/08 11:06:38 by trazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	mute_arg(int argc, char **argv)
{
	(void)argc;
	(void)argv;
}

int	draw_some_sphere(t_scene *scene)
{
	// t_vec3 camera_pos = vec3_create(0, 0, 5000);
	t_vec3 camera_pos = vec3_create(0.0, 0, 50);      
	t_vec3 sphere_center;
	float radius;                        

	// sphere_center = vec3_create(0.0, 0, -20.6);    
	// radius = 12.6;                                 
	// render_sphere(scene, camera_pos, sphere_center, radius);

	// sphere_center = vec3_create(0.0, 0, 0.6);    
	// radius = 3.6;                                 
	// render_sphere(scene, camera_pos, sphere_center, radius);
	
	// sphere_center = vec3_create(0.0, 10, -20.6);    
	// radius = 5.0;                                 
	// render_sphere(scene, camera_pos, sphere_center, radius);

	sphere_center = vec3_create(-10.0, 0, 10.6);    
	radius = 5.0;                                 
	render_sphere(scene, camera_pos, sphere_center, radius);

	// sphere_center = vec3_create(20, 10, -50);    
	// radius = 10.0;                                 
	// render_sphere(scene, camera_pos, sphere_center, radius);

	// sphere_center = vec3_create(-50, -50, -50);    
	// radius = 10.0;                                 
	// render_sphere(scene, camera_pos, sphere_center, radius);

	// sphere_center = vec3_create(-50, 50, -150);    
	// radius = 10.0;                                 
	// render_sphere(scene, camera_pos, sphere_center, radius);

	// sphere_center = vec3_create(50, -50, -100);    
	// radius = 10.0;                                 
	// render_sphere(scene, camera_pos, sphere_center, radius);
	return (0);
}

int	draw_some_cylinder(t_scene *scene)
{
	t_vec3 camera_pos = vec3_create(0.0,0, 50);
	t_vec3 cylinder_center;      
	t_vec3 axis_vec;
	float diameter;
	float height;      
	
	cylinder_center = vec3_create(-40, 4, -125);
	axis_vec = vec3_normalize(vec3_create(1.0, 1, 1.0));
	diameter = 20.0;
	height = 100.0;
	render_cylinder(scene, camera_pos, cylinder_center, axis_vec, diameter, height);
	cylinder_center = vec3_create(160, 0, -125);
	axis_vec = vec3_normalize(vec3_create(0.5, 2.5, 0.0));
	diameter = 5.0;
	height = 150.0;
	render_cylinder(scene, camera_pos, cylinder_center, axis_vec, diameter, height);
	cylinder_center = vec3_create(-50, 0, -75);
	axis_vec = vec3_normalize(vec3_create(0.0, 0.0, 1.0));
	diameter = 10.0;
	height = 75.0;
	render_cylinder(scene, camera_pos, cylinder_center, axis_vec, diameter, height);
	//lava
	cylinder_center = vec3_create(-200, -500, -200);
	axis_vec = vec3_normalize(vec3_create(0.0, 1, 0.0));
	diameter = 20.0;
	height = 1000.0;
	render_cylinder(scene, camera_pos, cylinder_center, axis_vec, diameter, height);
	cylinder_center = vec3_create(200, -500, -200);
	axis_vec = vec3_normalize(vec3_create(0.0, 1, 0.0));
	diameter = 20.0;
	height = 1000.0;
	render_cylinder(scene, camera_pos, cylinder_center, axis_vec, diameter, height);
	cylinder_center = vec3_create(-500, -145, -200);
	axis_vec = vec3_normalize(vec3_create(1.0, 0 , 0.0));
	diameter = 20.0;
	height = 1000.0;
	render_cylinder(scene, camera_pos, cylinder_center, axis_vec, diameter, height);
	return (0);
}

int	draw_some_plane(t_scene *scene)
{
	t_vec3 camera_pos = vec3_create(10.0,0, 50);      
	t_vec3 plane_point;
	t_vec3 plane_normal;

	

// 	// Test case 2: Vertical plane (like a wall)
camera_pos = vec3_create(0.0, 0.0, 50.0);
plane_point = vec3_create(0.0, 0.0, -20.0);
plane_normal = vec3_normalize(vec3_create(0.0, 0.0, 1.0));  // Normal pointing towards camera
	render_plane(scene, camera_pos, plane_point, plane_normal);

// // Test case 1: Horizontal Plane (Ceiling-like)
plane_point = vec3_create(0.0,50,-100.0);
	plane_normal = vec3_normalize(vec3_create(0.0, 1,0.1));
	render_plane(scene, camera_pos, plane_point, plane_normal);

// // Test case 3: Tilted Plane
// camera_pos = vec3_create(0.0, -20.0, -50.0);
// plane_point = vec3_create(0.0, 0.0, 0.0);
// plane_normal = vec3_normalize(vec3_create(0.3, 0.7, 0.0));  // Tilted upward and to the right
// render_plane(scene, camera_pos, plane_point, plane_normal);

// // Test case 4: Ground Plane (Floor-like)
// camera_pos = vec3_create(0.0, 25.0, 0.0);
// plane_point = vec3_create(0.0, 50.0, 0.0);
// plane_normal = vec3_normalize(vec3_create(0.0, 1.0, 0.0));  // Normal pointing upward
// // // light_pos = vec3_create(0.0, 20.0, 0.0);  // Light positioned above the plane
// render_plane(scene, camera_pos, plane_point, plane_normal);

	return (0);
}
