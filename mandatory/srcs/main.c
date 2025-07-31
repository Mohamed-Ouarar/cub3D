#include "../includes/cub3d.h"

int main(int ac, char **av)
{
	t_program	prog;

	ft_memset(&prog, 0, sizeof(prog));
	if (init_and_pars_map(&prog, ac, av) == ERROR)
		cleanup_exit(&prog);
	return (SUCCESS);
}
