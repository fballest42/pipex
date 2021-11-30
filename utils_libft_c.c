/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 08:25:12 by fballest          #+#    #+#             */
/*   Updated: 2021/11/30 19:18:12 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

char	*ft_strchr2(const char *str, char c)
{
	int				i;
	unsigned char	ch;
	char			*p;

	i = 0;
	p = (char *)str;
	ch = c + '\0';
	while (p[i] != '\0')
	{
		if (p[i] == ch)
			return (p + i + 1);
		i++;
	}
	if (ch == '\0')
		return (p + i + 1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *str, size_t n)
{
	char		*c;
	size_t		i;

	c = (char *)str;
	i = 0;
	while (i < n)
	{
		*c = '\0';
		c++;
		i++;
	}
}
