/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:43:42 by ferafano          #+#    #+#             */
/*   Updated: 2024/12/03 10:51:51 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int main(int argc, char *argv[])
{
	if (argc != 2 || file_parser(argv[1]) == 1)
		return (1);
	printf("\033[32mparse success\n\033[0m");
	return (0);
}
