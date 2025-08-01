/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasing_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:15:19 by mait-you          #+#    #+#             */
/*   Updated: 2025/08/01 14:00:41 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_arg_as_num(char *str)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	if (str[i] == '-' || str[i] == '+')
		return (error_msg("color", str, "value must be an unsigned integer"),
			ft_allocate(NULL, 0, FREE_ONE, str), -2);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (error_msg("color", str, "value must contain only digits"),
				ft_allocate(NULL, 0, FREE_ONE, str), -2);
		r = r * 10 + (str[i] - '0');
		if (r > 255)
			return (error_msg("color", str, "value must be between 0 and 255"),
				ft_allocate(NULL, 0, FREE_ONE, str), -2);
		i++;
	}
	return (ft_allocate(NULL, 0, FREE_ONE, str), r);
}

static int	validate_colors(char *line, t_color *colors, int *valid)
{
	char	**num_str;
	int		i;

	if (!line || !*line)
		return (ERROR);
	skip_white_space(&line);
	num_str = ft_split(line, ',');
	i = -1;
	while (num_str && num_str[++i])
		;
	if (i != 3)
		return (error_msg("colors", NULL, "expected format: R,G,B"),
			ft_free_args(num_str), ERROR);
	i = 0;
	colors->r = get_arg_as_num(ft_strtrim(num_str[i++], WHITE_SPACES));
	colors->g = get_arg_as_num(ft_strtrim(num_str[i++], WHITE_SPACES));
	colors->b = get_arg_as_num(ft_strtrim(num_str[i++], WHITE_SPACES));
	ft_free_args(num_str);
	if (colors->r == -2 || colors->g == -2 || colors->b == -2)
		return (ERROR);
	(*valid)++;
	return (SUCCESS);
}

static int pars_colors(const t_colre_map *map, char *line, int *valid)
{
	int	i;

	if (!line || !*line)
		return (SUCCESS);
	skip_white_space(&line);
	i = 0;
	while (map[i].id)
	{
		if (!ft_strncmp(map[i].id, line, 1))
		{
			if (map[i].colors->r != -1)
				return (error_msg("colors", map[i].id, "redeclared"));
			line += 1;
			if (!ft_strrchr(WHITE_SPACES, *line))
				return (SUCCESS);
			return (validate_colors(line, map[i].colors, valid));
		}
		i++;
	}
	return (SUCCESS);
}

static int	check_existens(const t_colre_map *map)
{
	int	i;
	int	exit_status;

	i = 0;
	exit_status = SUCCESS;
	while (map[i].id)
	{
		if (map[i].colors->r == -1)
		{
			error_msg("colors", map[i].id, "missing colors");
			exit_status = ERROR;
		}
		i++;
	}
	return (exit_status);
}

int get_colors(t_program *prog, t_config *config, int *line_offset_color)
{
	const t_colre_map	map[] = {\
		{"F", &config->floor_color}, \
		{"C", &config->ceiling_color}, \
		{NULL, NULL}, \
	};
	char				*line;
	int					valid;
	

	line = get_next_line(prog->fd_file_path_color);
	valid = 0;
	while (line && valid < 2)
	{
		(*line_offset_color)++;
		if (pars_colors(map, line, &valid) == ERROR)
			return (ft_allocate(NULL, 0, FREE_ONE, line), ERROR);
		line = ft_allocate(NULL, 0, FREE_ONE, line);
		if (valid < 2)
			line = get_next_line(prog->fd_file_path_color);
	}
	if (check_existens(map))
		return (ERROR);
	printf("F[R][%d]\n", config->floor_color.r);
	printf("F[G][%d]\n", config->floor_color.g);
	printf("F[b][%d]\n", config->floor_color.b);
	printf("C[R][%d]\n", config->ceiling_color.r);
	printf("C[G][%d]\n", config->ceiling_color.g);
	printf("C[b][%d]\n", config->ceiling_color.b);
	return (SUCCESS);
}
