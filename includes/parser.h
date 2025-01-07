/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:16:36 by trazanad          #+#    #+#             */
/*   Updated: 2024/12/23 11:19:12 by trazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H

# define PARSER_H

# include "clib.h"

# include "shape.h"

typedef struct s_ambient_lightning
{
	double lightning_ratio;
	int color;
} t_ambient_lightning;

typedef struct s_camera
{
	t_vec3 position;
	t_vec3 orientation;
	int field_view;
} t_camera;

typedef struct s_light
{
	t_vec3 position;
	double brightness_ratio;
	int color;
} t_light;

typedef struct s_data
{
	t_ambient_lightning *ambient_lightning;
	t_camera *camera;
	t_light *light;
	t_shape *shape;
} t_data;

typedef struct s_count
{
	int a_l;
	int cam;
	int light;
} t_count;

int		parse_file(char *filename, t_data *data);
char	**ft_split(char const *s, char c);
void	free_split(char **str);
int		valid_range_ambient(char **str2, t_data *data);
double	ft_atof(const char *str);
int		is_valid_float(char *str, int x);
int		check_first_and_count_param(char *str, t_count *count, t_data *data);
int		check_file_extention(char *filename);
int		check_valid_rgb(char *color);
int		ft_atoi(const char *nptr);
int		ft_valid_int(const char *str);
int		check_valid_coordinate(char *cord, t_vec3 *vec3);
int		valid_range_camera(char **str2, t_data *data);
int		check_3dnormaliser(char *cord, t_vec3 *vec3);
int		valid_range_light(char **str2, t_data *data);
int		valid_range_sphere(char **str2, t_data *data);
int		valid_range_plane(char **str2, t_data *data);
int		valid_range_cylinder(char **str2, t_data *data);
int		alloc_data_default(t_data *data);
void	add_back_sphere(t_sphere **lst, t_sphere *new);
void	add_back_plane(t_plane **lst, t_plane *new);
void	add_back_cylinder(t_cylinder **lst, t_cylinder *new);
void	free_scene_data(t_data *data);
void    print_data(t_data *data);

#endif
