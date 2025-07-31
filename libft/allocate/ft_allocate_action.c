/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate_action.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:34:40 by mait-you          #+#    #+#             */
/*   Updated: 2025/06/19 11:51:26 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_allocate.h"

static void	*error_cleanup(t_program *prog)
{
	(void)prog;
	ft_putstr_fd_sa(ERR_MALLOC_FAILED, STDERR_FILENO);
	exit(ERROR);
	return (NULL);
}

void	*allocate_ptr(t_program *prog, t_allocation_node **head, size_t size)
{
	void	*ptr;

	ptr = ft_calloc_sa(size);
	if (!ptr)
		return (error_cleanup(prog));
	if (add_to_tracking(head, ptr) == NULL)
	{
		free(ptr);
		return (error_cleanup(prog));
	}
	return (ptr);
}

void	*free_all(t_allocation_node **head)
{
	t_allocation_node	*current;
	t_allocation_node	*next;

	if (!head || !*head)
		return (NULL);
	current = *head;
	while (current)
	{
		next = current->next;
		if (current->ptr)
			free(current->ptr);
		free(current);
		current = next;
	}
	*head = NULL;
	return (NULL);
}

void	*free_specific(t_allocation_node **head, void *ptr)
{
	t_allocation_node	*current;
	t_allocation_node	*prev;
	void				*result;

	if (!ptr)
		return (NULL);
	current = *head;
	prev = NULL;
	result = ptr;
	while (current)
	{
		if (current->ptr == ptr)
		{
			if (prev)
				prev->next = current->next;
			else
				*head = current->next;
			free(current->ptr);
			free(current);
			return (NULL);
		}
		prev = current;
		current = current->next;
	}
	return (result);
}

void	*add_to_tracking(t_allocation_node **head, void *ptr)
{
	t_allocation_node	*new_node;

	if (!ptr || !head)
		return (NULL);
	new_node = ft_calloc_sa(sizeof(t_allocation_node));
	if (!new_node)
		return (NULL);
	new_node->ptr = ptr;
	new_node->next = *head;
	*head = new_node;
	return (ptr);
}
