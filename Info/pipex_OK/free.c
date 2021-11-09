/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:20:33 by milmi             #+#    #+#             */
/*   Updated: 2021/06/05 12:53:19 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_if(void *var)
{
	if (var)
		free(var);
}

void	free_double(char **mem)
{
	int	i;

	i = 0;
	while (mem[i])
	{
		free(mem[i]);
		i++;
	}
	free(mem);
}

void	free_temp(t_temp *temp)
{
	free(temp->path);
	free(temp->cmdpath);
}

void	free_struct_norm(t_data **data)
{
	int	i;

	i = 0;
	while ((*data)->cmd2[i])
	{
		free((*data)->cmd2[i]);
		i++;
	}
	if ((*data)->cmd1)
		free((*data)->cmd1);
	if ((*data)->cmd2)
		free((*data)->cmd2);
	i = 0;
	if ((*data)->absolute1 == 0 || (*data)->absolute2 == 0)
	{
		while ((*data)->path[i])
		{
			free((*data)->path[i]);
			i++;
		}
	}
	if ((*data)->path)
		free((*data)->path);
}

void	free_struct(t_data **data)
{
	int	i;

	i = 0;
	if ((*data)->pathcmd1)
		free((*data)->pathcmd1);
	if ((*data)->pathcmd2 != NULL)
		free((*data)->pathcmd2);
	if ((*data)->infile)
		free((*data)->infile);
	if ((*data)->outfile)
		free((*data)->outfile);
	while ((*data)->cmd1[i])
	{
		free((*data)->cmd1[i]);
		i++;
	}
	free_struct_norm(data);
}
