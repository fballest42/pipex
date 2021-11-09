/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:07:58 by fballest          #+#    #+#             */
/*   Updated: 2021/11/09 23:06:01 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_printerror(char *str, int error, t_pipex *pipex)
{
	printf("%s\n", str);
	if (pipex->path)
		ft_matrixfree((void **)pipex->path);
	if (pipex->env)
		ft_matrixfree((void **)pipex->env);
	if (pipex->cmd_1)
		ft_matrixfree((void **)pipex->cmd_1);
	if (pipex->cmd_2)
		ft_matrixfree((void **)pipex->cmd_2);
	if (pipex->expath)
		free (pipex->expath);
	if (pipex->expath2)
		free (pipex->expath2);
	free(pipex);
	exit(error * -1);
}

char	**add_slash_paths(t_pipex *pipex)
{
	char	**aux;
	int		i;

	i = ft_matrixlines(pipex->path);
	aux = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (pipex->path[i])
	{
		aux[i] = ft_strjoin(pipex->path[i], "/");
		free (pipex->path[i]);
		i++;
	}
	free (pipex->path);
	aux[i] = NULL;
	return (aux);
}

void	add_command_path(t_pipex *pipex)
{
	int		i;
	char	*aux1;
	char	*aux2;

	i = 0;
	aux1 = NULL;
	aux2 = NULL;
	while (pipex->path[i])
	{
		aux1 = ft_strjoin(pipex->path[i], pipex->cmd_1[0]);
		if (!access(aux1, X_OK))
			pipex->expath = aux1;
		aux2 = ft_strjoin(pipex->path[i], pipex->cmd_2[0]);
		if (!access(aux2, X_OK))
			pipex->expath2 = aux2;
		i++;
	}
	if (!pipex->expath || !pipex->expath2)
		ft_printerror("Error:\n", 9, pipex);
}

char	**take_envs(char **env, t_pipex *pipex)
{
	int		i;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i])
		i++;
	pipex->env = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			pipex->path = ft_split(env[i], ':');
			if (!pipex->path)
				return (NULL);
		}
		pipex->env[i] = ft_strdup(env[i]);
		i++;
	}
	pipex->env[i] = NULL;
	return (pipex->env);
}

void	get_commands(char **argv, t_pipex *pipex)
{
	pipex->cmd_1 = ft_split(argv[2], ' ');
	pipex->cmd_2 = ft_split(argv[3], ' ');
	if (!pipex->cmd_1 || !pipex->cmd_2)
		ft_printerror("Error: Not enought parameters\n", 4, pipex);
}