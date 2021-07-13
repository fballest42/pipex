/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:07:58 by fballest          #+#    #+#             */
/*   Updated: 2021/07/13 16:11:30 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_printerror(char *str, int error, t_pipex *pipex)
{
	printf("%s\n", str);
	if (pipex->filein)
	{
		pipex->filein = NULL;
		free(pipex->filein);
	}
	if (pipex->fileout)
	{
		pipex->fileout = NULL;
		free(pipex->fileout);
	}
	free(pipex);
	exit(error);
}
