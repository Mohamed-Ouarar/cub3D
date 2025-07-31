/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:23:53 by mait-you          #+#    #+#             */
/*   Updated: 2025/07/31 15:12:41 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool is_white_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_close(int *fd)
{
	if (*fd == -1)
		return (ERROR);
	close(*fd);
	*fd = -1;
	return (SUCCESS);
}

int	is_emty_line(char *line)
{
	while (line && is_white_space(*line))
		line++;
	if (!*line || *line == '\n')
		return (SUCCESS);
	return (ERROR);
}

int	skip_white_space(char **str)
{
	if (!str || !*str)
		return (ERROR);
	while (**str && is_white_space(**str))
		(*str)++;
	return (SUCCESS);
}
