#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <stdbool.h>
# include <errno.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "../../libft/include/libft.h"
# include "../../libft/include/get_next_line.h"
# include "parsing.h"

# undef TITLE
# define TITLE "cub3D"

typedef struct s_program	t_program;
typedef struct s_config		t_config;
typedef struct s_color		t_color;
typedef enum e_dir			t_dir;

enum e_dir
{
	NO_DIR,
	NORTH,
	SOUTH,
	WEST,
	EAST,
};

struct s_color
{
	int 		r;
	int 		g;
	int 		b;
};

struct s_config
{
	void		*north_tex;
	void		*south_tex;
	void		*west_tex;
	void		*east_tex;
	t_color		floor_color;
	t_color		ceiling_color;
	char		**map;
	int			player_x;
	int			player_y;
	t_dir		player_dir;
};

struct s_program
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*file_path;
	int			fd_file_path_tex;
	int			fd_file_path_color;
	int			fd_file_path_map;
	t_config	config;
};

#endif