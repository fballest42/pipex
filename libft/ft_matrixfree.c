/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:45:40 by fballest          #+#    #+#             */
/*   Updated: 2021/11/05 09:54:18 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_matrixfree(void **str)
{
    int     i;
    
    i = 0;
    while (str[i])
    {
        free (str[i]);
        str[i] = (void *)0;
        i++;
    }
    free (str);
    str = (void *)0;
}
