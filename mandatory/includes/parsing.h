/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:15:33 by mait-you          #+#    #+#             */
/*   Updated: 2025/08/01 13:50:14 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

# undef WHITE_SPACES
# define WHITE_SPACES " \t\n\v\f\r"

typedef struct s_config		t_config;
typedef struct s_tex_map	t_tex_map;
typedef struct s_colre_map	t_colre_map;
typedef struct s_tex_src	t_tex_src;
typedef struct s_color		t_color;


struct s_tex_map
{
	char		*id;
	char		**target;
	void		**src;
};

struct s_colre_map
{
	char		*id;
	t_color		*colors;
};

struct s_tex_src
{
	char		*north_tex;
	char		*south_tex;
	char		*west_tex;
	char		*east_tex;
};

int		init_and_pars_map(t_program *prog, int ac, char **av);
int		get_textures(t_program *prog, t_config *config, int *line_offset_tex);
int 	get_colors(t_program *prog, t_config *config, int *line_offset_color);
int		error_msg(char *msg_type, char *the_error, char *msg);
void	error_cleanup_exit(\
	t_program *prog, char *msg_type, char *the_error, char *msg);

bool	is_white_space(char c);
int		ft_close(int *fd);
int		is_emty_line(char *line);
int		skip_white_space(char **str);
void	cleanup_exit(t_program *prog);

void	ft_free_args(char **str);
int get_map(t_program *prog, t_config *config);


#endif
