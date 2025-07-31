/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:11:58 by mait-you          #+#    #+#             */
/*   Updated: 2025/06/29 12:38:27 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_allocate.h"

void	*ft_allocate(
	t_program *prog, size_t size, t_action action, void *ptr)
{
	static t_allocation_node	*allocations = NULL;
	static t_program			*ptr_prog = NULL;
	void						*result;

	result = ptr;
	if (action == INIT && prog && !ptr_prog)
		ptr_prog = prog;
	if (action == ALLOCATE)
		result = allocate_ptr(ptr_prog, &allocations, size);
	else if (action == FREE_ALL)
		result = free_all(&allocations);
	else if (action == FREE_ONE)
		result = free_specific(&allocations, ptr);
	else if (action == ADD_TO_TRACK)
		result = add_to_tracking(&allocations, ptr);
	return (result);
}
