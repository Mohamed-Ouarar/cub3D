/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:15:19 by mait-you          #+#    #+#             */
/*   Updated: 2025/07/31 18:47:09 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	pars_file_path(t_program *prog, int ac, char *file_path)
{
	char	*last_slash;

	if (ac != 2)
		return (error_msg("Usage", NULL, "./cub3D <path_of_map>"));
	prog->file_path = ft_strtrim(file_path, WHITE_SPACES);
	file_path = prog->file_path;
	last_slash = ft_strrchr(file_path, '/');
	if (!last_slash)
		return (ERROR);
	file_path = last_slash;
	while (*file_path && *file_path != '.')
		file_path++;
	while (*file_path && *file_path == '.')
		file_path++;
	if (ft_strncmp("cub", file_path, 4))
		return (error_msg("path of map", NULL, \
			"should ending with the `.cub` extension"));
	return (SUCCESS);
}

int	init_and_pars_map(t_program *prog, int ac, char **av)
{
	if (pars_file_path(prog, ac, av[1]) == ERROR)
		return (ERROR);
	prog->fd_map = open(prog->file_path, O_RDONLY);
	if (prog->fd_map == -1)
		return (error_msg("open", "failde to open", prog->file_path));
	prog->mlx_ptr = mlx_init();
	if (!prog->mlx_ptr)
		return (error_msg("mlx_init()", NULL, "MLX init failed"));
	// prog->win_ptr = mlx_new_window(prog->mlx_ptr,200, 200,TITLE);
	// if (!prog->win_ptr)
	// 	return (error_msg("mlx_init()", NULL, "MLX init failed"));
	if (get_textures(prog, &prog->config) == ERROR)
		return (ERROR);
	printf("north_tex[%s]\n", prog->config.north_tex);
	printf("south_tex[%s]\n", prog->config.south_tex);
	printf(" west_tex[%s]\n", prog->config.west_tex);
	printf(" east_tex[%s]\n", prog->config.east_tex);
	return (SUCCESS);
}
