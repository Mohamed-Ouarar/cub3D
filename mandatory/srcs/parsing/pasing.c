/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:15:19 by mait-you          #+#    #+#             */
/*   Updated: 2025/08/01 13:52:16 by mait-you         ###   ########.fr       */
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



// int	get_textures_colors(t_program *prog, t_config *config)
// {
	
// 	return (SUCCESS);
// }

int init_vars(t_program *prog)
{
	ft_memset(prog, 0, sizeof(prog));
	ft_allocate(prog, 0, INIT, NULL);
	prog->fd_file_path_tex = -1;
	prog->fd_file_path_color = -1;
	prog->fd_file_path_map = -1;
	prog->config.floor_color.r = -1;
	prog->config.floor_color.g = -1;
	prog->config.floor_color.b = -1;
	prog->config.ceiling_color.r = -1;
	prog->config.ceiling_color.g = -1;
	prog->config.ceiling_color.b = -1;
	prog->config.player_x = -1;
	prog->config.player_y = -1;
	prog->config.player_dir = NO_DIR;
	// prog->mlx_ptr = mlx_init();
	// if (!prog->mlx_ptr)
	// 	return (error_msg("mlx_init()", NULL, "MLX init failed"));
	// prog->win_ptr = mlx_new_window(prog->mlx_ptr,1920, 1080,TITLE);
	// if (!prog->win_ptr)
	// 	return (error_msg("mlx_init()", NULL, "MLX init failed"));
	return (SUCCESS);
}

int	init_and_pars_map(t_program *prog, int ac, char **av)
{
	int	line_offset_tex;
	int	line_offset_color;
	// int	line_offset_map;

	if (init_vars(prog) == ERROR)
		return (ERROR);
	if (pars_file_path(prog, ac, av[1]) == ERROR)
		return (ERROR);
	
	line_offset_tex = 0;
	prog->fd_file_path_tex = open(prog->file_path, O_RDONLY);
	if (prog->fd_file_path_tex == -1)
		return (error_msg("open", "failde to open", prog->file_path));
	if (get_textures(prog, &prog->config, &line_offset_tex) == ERROR)
		return (ERROR);
	
	line_offset_color = 0;
	prog->fd_file_path_color = open(prog->file_path, O_RDONLY);
	if (prog->fd_file_path_color == -1)
		return (error_msg("open", "failde to open", prog->file_path));
	if (get_colors(prog, &prog->config, &line_offset_color) == ERROR)
		return (ERROR);
	// prog->fd_file_path_map = open(prog->file_path, O_RDONLY);
	// if (prog->fd_file_path_map == -1)
	// 	return (error_msg("open", "failde to open", prog->file_path));
	// if (get_map(prog, &prog->config) == ERROR)
	// 	return (ERROR);
	return (SUCCESS);
}
