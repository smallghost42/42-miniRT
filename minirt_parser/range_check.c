/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:18:47 by ferafano          #+#    #+#             */
/*   Updated: 2024/12/15 10:27:14 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int valid_range_ambient(char **str2, t_data *data)
{
	if (is_valid_float(str2[1], 1))
		return (1);
	data->ambient_lightning->lightning_ratio = ft_atof(str2[1]);
	if (data->ambient_lightning->lightning_ratio < 0.0 ||
		data->ambient_lightning->lightning_ratio > 1.0)
		return (1);
	if (check_valid_rgb(str2[2]))
		return (1);
	// data->ambient_lightning->color = ;
	return (0);
}

int valid_range_camera(char **str2, t_data *data)
{
	if (check_valid_coordinate(str2[1], &data->camera->position))
		return (1);
	if (check_3dnormaliser(str2[2], &data->camera->orientation))
		return (1);
	if (ft_valid_int(str2[3]) || ft_atoi(str2[3]) < 0 || ft_atoi(str2[3]) > 180)
		return (1);
	data->camera->field_view = ft_atoi(str2[3]);
	return (0);
}

int valid_range_light(char **str2, t_data *data)
{
	if (check_valid_coordinate(str2[1], &data->light->position))
		return (1);
	if (is_valid_float(str2[2], 1))
		return (1);
	data->light->brightness_ratio = ft_atof(str2[2]);
	if (data->light->brightness_ratio < 0.0 || data->light->brightness_ratio > 1.0)
		return (1);
	if (check_valid_rgb(str2[3])) // for bonus only
		return (1);
	// data->light->color = ;
	return (0);
}
