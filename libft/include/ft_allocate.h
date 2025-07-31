/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:34:35 by mait-you          #+#    #+#             */
/*   Updated: 2025/07/31 16:58:00 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALLOCATE_H
# define FT_ALLOCATE_H

# include <unistd.h>
# include <stdlib.h>

# undef SUCCESS
# define SUCCESS 0

# undef ERROR
# define ERROR 1

# undef CUB3D_PROMPT
# define CUB3D_PROMPT	"\e[1;31mcub3D\e[1;32m : \e[0m Error\n"

# undef ERR_MALLOC_FAILED
# define ERR_MALLOC_FAILED ": \e[1;33mALLOCATION\e[90m: malloc failed\e[0m\n"

typedef struct s_program		t_program;

typedef struct s_allocation_node
{
	void						*ptr;
	struct s_allocation_node	*next;
}	t_allocation_node;

typedef enum e_action
{
	INIT,
	ALLOCATE,
	FREE_ALL,
	FREE_ONE,
	ADD_TO_TRACK,
}	t_action;

void	*ft_allocate(\
	t_program *prog, size_t size, t_action action, void *ptr);

void	*allocate_ptr(t_program *prog, t_allocation_node **head, size_t size);
void	*free_all(t_allocation_node **head);
void	*free_specific(t_allocation_node **head, void *ptr);
void	*add_to_tracking(t_allocation_node **head, void *ptr);

void	*ft_memset_sa(void *b, int c, size_t len);
void	*ft_calloc_sa(size_t size);
void	ft_putstr_fd_sa(char *s, int fd);

#endif