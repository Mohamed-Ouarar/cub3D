/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:42:06 by mait-you          #+#    #+#             */
/*   Updated: 2025/07/30 16:53:38 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*ft_strcpy_adv(char *dst, char *src)
{
	while (src && *src)
		*dst++ = *src++;
	*dst = 0;
	return (dst);
}

static size_t	calculate_buffer_size(
	char *msg_type, char *the_error, char *msg)
{
	size_t	size;

	size = 0;
	if (CUB3D_PROMPT)
		size += ft_strlen(CUB3D_PROMPT);
	if (msg_type)
		size += ft_strlen(msg_type) + 7;
	if (the_error)
		size += ft_strlen(the_error) + 11;
	if (msg)
	{
		size += 7;
		if (!*msg)
			size += ft_strlen(strerror(errno));
		else
			size += ft_strlen(msg);
	}
	size += 5;
	return (size + 1);
}

static int	make_error_msg(
	char **ptr, char *msg_type, char *the_error, char *msg)
{
	if (msg_type)
	{
		*ptr = ft_strcpy_adv(*ptr, "\e[1;33m");
		*ptr = ft_strcpy_adv(*ptr, msg_type);
	}
	if (the_error)
	{
		*ptr = ft_strcpy_adv(*ptr, ": \e[1;36m'");
		*ptr = ft_strcpy_adv(*ptr, the_error);
		*ptr = ft_strcpy_adv(*ptr, "'");
	}
	if (msg)
	{
		*ptr = ft_strcpy_adv(*ptr, ": \e[90m");
		if (!*msg)
			*ptr = ft_strcpy_adv(*ptr, strerror(errno));
		else
			*ptr = ft_strcpy_adv(*ptr, msg);
	}
	return (SUCCESS);
}

int	error_msg(char *msg_type, char *the_error, char *msg)
{
	char	*error_buffer;
	char	*ptr;
	size_t	buffer_size;

	buffer_size = calculate_buffer_size(msg_type, the_error, msg);
	error_buffer = ft_allocate(NULL, buffer_size, ALLOCATE, NULL);
	ptr = error_buffer;
	if (CUB3D_PROMPT)
		ptr = ft_strcpy_adv(ptr, CUB3D_PROMPT);
	make_error_msg(&ptr, msg_type, the_error, msg);
	ft_strcpy_adv(ptr, "\e[0m\n");
	ft_putstr_fd(error_buffer, STDERR_FILENO);
	error_buffer = ft_allocate(NULL, 0, FREE_ONE, error_buffer);
	return (ERROR);
}


