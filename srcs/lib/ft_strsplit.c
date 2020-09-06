/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:41:38 by hde-ghel          #+#    #+#             */
/*   Updated: 2018/11/27 19:29:42 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_nbwords(const char *s, char c)
{
	int		nb;
	int		in;

	nb = 0;
	in = 0;
	while (*s != '\0')
	{
		if (in == 1 && *s == c)
			in = 0;
		if (in == 0 && *s != c)
		{
			in = 1;
			nb++;
		}
		s++;
	}
	return (nb);
}

static int	ft_wordlen(const char *s, char c, int i)
{
	int		len;

	len = 0;
	while (s[i + len] != c && s[i + len] != '\0')
		len++;
	return (len);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		i;
	int		k;
	int		len;
	int		nb_words;

	if (!s || !c)
		return (NULL);
	i = -1;
	k = 0;
	nb_words = ft_nbwords((const char *)s, c);
	if (!(tab = (char **)malloc(sizeof(*tab) * (nb_words + 1))))
		return (NULL);
	while (s[++i] != '\0')
	{
		if (s[i] != c)
		{
			len = ft_wordlen(s, c, i);
			if (!(tab[k++] = ft_strsub(s, i, len)))
				return (ft_freetab(tab, k));
			i = i + len - 1;
		}
	}
	tab[k] = NULL;
	return (tab);
}
