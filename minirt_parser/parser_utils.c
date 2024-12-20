/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:57:36 by ferafano          #+#    #+#             */
/*   Updated: 2024/12/10 10:34:31 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int check_file_extention(char *filename)
{
	char *str;

	if (ft_strlen(filename) < 4)
		return (0);
	str = ft_substr(filename, ft_strlen(filename) - 3, 3);
	if (strcmp(str, ".rt"))
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

void free_split(char **str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

int check_first_and_count_param(char *str, t_count *count)
{
	t_data *data;
	char **str2;
	int i;

	i = 0;
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	str2 = ft_split(str, ' ');
	if (!str2)
		return (1);
	while (str2[i])
		i++;
	if (!strcmp(str2[0], "A") && i == 3 && !valid_range_ambient(str2))
		count->a_l += 1;
	else if (!strcmp(str2[0], "C") && i == 4 && !valid_range_camera(str2))
		count->cam += 1;
	else if (!strcmp(str2[0], "L") && i == 4 && !valid_range_light(str2))
		count->light += 1;
	else if (!strcmp(str2[0], "sp") && i == 4 && !valid_range_sphere(str2))
		ft_lstadd_back(data->shape->sphere, create_sphere(str2));
	else if (!strcmp(str2[0], "pl") && i == 4 && !valid_range_plane(str2))
		;
	else if (!strcmp(str2[0], "cy") && i == 6 && !valid_range_cylinder(str2))
		;
	else
	{
		free_split(str2);
		return (1);
	}
	free_split(str2);
	return (0);
}
