#include "../../includes/cub3d.h"

int	error_msg(char *msg_type, char *the_error, char *msg)
{
	static bool printed = false;

	if (CUB3D_PROMPT && printed == false)
	{
		ft_putstr_fd(CUB3D_PROMPT, STDERR_FILENO);
		printed = true;
	}
	if (msg_type)
	{
		ft_putstr_fd("\e[1;33m", STDERR_FILENO);
		ft_putstr_fd(msg_type, STDERR_FILENO);
	}
	if (the_error)
	{
		ft_putstr_fd(": \e[1;36m'", STDERR_FILENO);
		ft_putstr_fd(the_error, STDERR_FILENO);
		ft_putstr_fd("'", STDERR_FILENO);
	}
	if (msg)
	{
		ft_putstr_fd(": \e[90m", STDERR_FILENO);
		if (!*msg)
			ft_putstr_fd(strerror(errno), STDERR_FILENO);
		else
			ft_putstr_fd(msg, STDERR_FILENO);
	}
	ft_putstr_fd("\e[0m\n", STDERR_FILENO);
	return (ERROR);
}

void	cleanup_exit(t_program *prog)
{
	if (prog->file_path)
		prog->file_path = ft_allocate(NULL, 0, FREE_ONE, prog->file_path);
	if (prog->mlx_ptr && prog->config.north_tex)
		mlx_destroy_image(prog->mlx_ptr, prog->config.north_tex);
	if (prog->mlx_ptr && prog->config.south_tex)
		mlx_destroy_image(prog->mlx_ptr, prog->config.south_tex);
	if (prog->mlx_ptr && prog->config.west_tex)
		mlx_destroy_image(prog->mlx_ptr, prog->config.west_tex);
	if (prog->mlx_ptr && prog->config.east_tex)
		mlx_destroy_image(prog->mlx_ptr, prog->config.east_tex);
	if (prog->mlx_ptr && prog->win_ptr)
		mlx_destroy_window(prog->mlx_ptr, prog->win_ptr);
	ft_close(&prog->fd_map);
	prog = ft_allocate(NULL, 0, FREE_ALL, NULL);
	exit(ERROR);
}

void	error_cleanup_exit(
	t_program *prog, char *msg_type, char *the_error, char *msg)
{
	error_msg(msg_type, the_error, msg);
	cleanup_exit(prog);
}
