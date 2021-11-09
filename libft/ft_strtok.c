/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:16:48 by fballest          #+#    #+#             */
/*   Updated: 2021/11/05 10:18:45 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(const char *str, char c)
{
	int		i;
	char	*dest;

	i = 0;
	dest = ft_strdup(str);
	while (str[i] && str[i] != c)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	if (!dest)
		return (NULL);
	return (dest);
}
