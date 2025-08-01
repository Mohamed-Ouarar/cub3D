#include "../includes/cub3d.h"

int main(int ac, char **av)
{
	t_program	prog;

	if (init_and_pars_map(&prog, ac, av) == ERROR)
		cleanup_exit(&prog);
	cleanup_exit(&prog);
	return (SUCCESS);
}
