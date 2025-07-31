/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasing_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:15:19 by mait-you          #+#    #+#             */
/*   Updated: 2025/07/31 18:27:05 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	validate_texture_path(char *line, char **target)
{
	char	*backup;
	char	*ext_pos;

	if (!line || !*line)
		return (ERROR);
	skip_white_space(&line);
	backup = line;
	ext_pos = ft_strrchr(line, '.');
	if (!ext_pos)
		return (error_msg("texture", "missing file extension", backup));
	if (ft_strncmp(ext_pos + 1, "xpm", 3) != 0)
		return (error_msg("texture", "should end with the `.xpm` extension", backup));
	if (*(ext_pos + 4) != '\0' && !ft_strchr(WHITE_SPACES, *(ext_pos + 4)))
		return (error_msg("texture", "should end with the `.xpm` extension", backup));
	*target = ft_strtrim(backup, WHITE_SPACES);
	if (!*target)
		return (ERROR);
	return (SUCCESS);
}

static int	pars_textures(const t_texmap *map, char *line)
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
			return (validate_texture_path(line, map[i].target));
		}
		i++;
	}
	return (SUCCESS);
}

static int	check_existens(const t_texmap *map)
{
	int	i;
	int	error_found;

	i = 0;
	error_found = 0;
	while (map[i].id)
	{
		if (!*map[i].target || !**map[i].target)
		{
			error_msg("texture", map[i].id, "missing texture path");
			if (error_found)
				*map[i].target = ft_allocate(NULL, 0, FREE_ONE, *map[i].target);
			error_found = 1;
		}
		i++;
	}
	return (SUCCESS);
}

static int	load_textures(t_program *prog, const t_texmap *map)
{
	int	width;
	int	height;
	int	i;

	i = 0;
	while (map[i].id)
	{
		*map[i].src = mlx_xpm_file_to_image(
			prog->mlx_ptr, *map[i].target, &width, &height);
		if (!*map[i].src)
			return (error_msg("texture", map[i].id, "failed to load texture"));
		i++;
	}
	return (SUCCESS);
}

int	get_textures(t_program *prog, t_config *config)
{
	t_tex_src		textures;
	const t_texmap	map[] = {
	{"NO", &textures.north_tex, &config->north_tex}, \
	{"SO", &textures.south_tex, &config->south_tex}, \
	{"WE", &textures.west_tex, &config->west_tex}, \
	{"EA", &textures.east_tex, &config->east_tex}, \
	{NULL, NULL, NULL}
	};
	char			*line;

	ft_memset(&textures, 0, sizeof(t_tex_src));
	line = get_next_line(prog->fd_map);
	while (line)
	{
		if (pars_textures(map, line) == ERROR)
			return (ft_allocate(NULL, 0, FREE_ONE, line), ERROR);
		line = ft_allocate(NULL, 0, FREE_ONE, line);
		line = get_next_line(prog->fd_map);
	}
	if (check_existens(map))
		return (ERROR);
	if (load_textures(prog, map))
		return (ERROR);
	return (SUCCESS);
}
