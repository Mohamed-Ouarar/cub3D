/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasing_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:15:19 by mait-you          #+#    #+#             */
/*   Updated: 2025/08/01 11:36:57 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int pars_map(t_config *config)
{
	return (SUCCESS);
}

int get_map(t_program *prog, t_config *config)
{
	char				*line;

	line = get_next_line(prog->fd_map);
	while (line)
	{
		if (pars_map(map, line, &valid) == ERROR)
			return (ft_allocate(NULL, 0, FREE_ONE, line), ERROR);
		line = ft_allocate(NULL, 0, FREE_ONE, line);
		line = get_next_line(prog->fd_map);
	}
	return (SUCCESS);
}
