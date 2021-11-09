/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsterase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 09:18:07 by fballest          #+#    #+#             */
/*   Updated: 2021/11/05 10:15:28 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lsterase(t_list *list)
{
	t_list	*aux;

	while (list)
	{
		aux = list;
		list = list->next;
		free(aux->content);
		free(aux);
		aux = NULL;
	}
}
