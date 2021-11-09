/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:40:16 by fballest          #+#    #+#             */
/*   Updated: 2021/11/05 10:24:15 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
