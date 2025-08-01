/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:17:14 by mait-you          #+#    #+#             */
/*   Updated: 2025/07/30 17:56:33 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	n_len(long int n)
{
	int	l;

	l = 0;
	if (n <= 0)
	{
		n = -n;
		l++;
	}
	while (n > 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

static void	ft_putnb(char *s, long int n)
{
	if (n > 9)
		ft_putnb(s - 1, n / 10);
	*s = '0' + (n % 10);
}

char	*ft_itoa(int n)
{
	long int	nb;
	int			len;
	char		*str;

	nb = n;
	len = n_len(nb);
	str = (char *)ft_allocate(NULL, len + 1, ALLOCATE, NULL);
	if (nb < 0)
	{
		*str = '-';
		nb = -nb;
	}
	ft_putnb(str + len - 1, nb);
	str[len] = '\0';
	return (str);
}
