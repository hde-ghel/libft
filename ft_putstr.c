/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 15:00:38 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/10/10 10:54:17 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int		i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		write(1, s, i);
	}

	/*
	if (s)
	{
		while (*s)
			write(1, s++, 1);
	}
	*/
}
