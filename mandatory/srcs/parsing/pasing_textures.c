/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasing_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:15:19 by mait-you          #+#    #+#             */
/*   Updated: 2025/08/01 13:48:12 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	validate_texture_path(char *line, char **target, int *valid)
{
	char	*backup;
	char	*last_backslash;

	if (!line || !*line)
		return (ERROR);
	skip_white_space(&line);
	backup = line;
	last_backslash = ft_strrchr(line, '.');
	if (!last_backslash)
		return (error_msg("texture", "missing file extension", backup));
	if (ft_strncmp(last_backslash + 1, "xpm", 3) != 0)
		return (error_msg("texture", "should end with the `.xpm` extension", backup));
	if (*(last_backslash + 4) && !ft_strchr(WHITE_SPACES, *(last_backslash + 4)))
		return (error_msg("texture", "should end with the `.xpm` extension", backup));
	*target = ft_strtrim(backup, WHITE_SPACES);
	if (!*target)
		return (ERROR);
	(*valid)++;
	return (SUCCESS);
}

static int	pars_textures(const t_tex_map *map, char *line, int *valid)
{
	int	i;

	if (!line || !*line)
		return (SUCCESS);
	skip_white_space(&line);
	i = 0;
	while (map[i].id)
	{
		if (!ft_strncmp(map[i].id, line, 2))
		{
			if (*map[i].target)
				return (error_msg("texture", map[i].id, "redeclared"));
			line += 2;
			if (!ft_strrchr(WHITE_SPACES, *line))
				return (error_msg("texture", map[i].id, "redeclared"));
			return (validate_texture_path(line, map[i].target, valid));
		}
		i++;
	}
	return (SUCCESS);
}

static int	check_existens(const t_tex_map *map)
{
	int	i;
	int	exit_status;

	i = 0;
	exit_status = SUCCESS;
	while (map[i].id)
	{
		if (!*map[i].target || !**map[i].target)
		{
			error_msg("texture", map[i].id, "missing texture path");
			if (exit_status)
				*map[i].target = ft_allocate(NULL, 0, FREE_ONE, *map[i].target);
			exit_status = ERROR;
		}
		i++;
	}
	return (exit_status);
}

// static int	load_textures(t_program *prog, const t_tex_map *map)
// {
// 	int	width;
// 	int	height;
// 	int	i;

// 	i = 0;
// 	while (map[i].id)
// 	{
// 		*map[i].src = mlx_xpm_file_to_image(
// 			prog->mlx_ptr, *map[i].target, &width, &height);
// 		if (!*map[i].src)
// 			return (error_msg("texture", map[i].id, "failed to load texture"));
// 		i++;
// 	}
// 	return (SUCCESS);
// }

int	get_textures(t_program *prog, t_config *config, int *line_offset_tex)
{
	t_tex_src		textures;
	const t_tex_map	map[] = {
	{"NO", &textures.north_tex, &config->north_tex}, \
	{"SO", &textures.south_tex, &config->south_tex}, \
	{"WE", &textures.west_tex, &config->west_tex}, \
	{"EA", &textures.east_tex, &config->east_tex}, \
	{NULL, NULL, NULL}
	};
	char			*line;
	int				valid;

	ft_memset(&textures, 0, sizeof(t_tex_src));
	line = get_next_line(prog->fd_file_path_tex);
	valid = 0;
	while (line && valid < 4)
	{
		(*line_offset_tex)++;
		if (pars_textures(map, line, &valid) == ERROR)
			return (ft_allocate(NULL, 0, FREE_ONE, line), ERROR);
		line = ft_allocate(NULL, 0, FREE_ONE, line);
		if (valid < 4)
			line = get_next_line(prog->fd_file_path_tex);
	}
	if (check_existens(map))
		return (ERROR);
	printf("north_tex[%s]\n", textures.north_tex);
	printf("south_tex[%s]\n", textures.south_tex);
	printf(" west_tex[%s]\n", textures.west_tex);
	printf(" east_tex[%s]\n", textures.east_tex);
	// if (load_textures(prog, map))
	// 	return (ERROR);
	return (SUCCESS);
}
