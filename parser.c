/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:07:58 by fballest          #+#    #+#             */
/*   Updated: 2021/12/01 15:52:08 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**add_slash_paths(t_pipex *pipex)
{
	char	**aux;
	int		i;

	if (!pipex->path)
		return (NULL);
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
	if (pipex->path && (access(pipex->cmd_1[0], X_OK)
			|| access(pipex->cmd_2[0], X_OK)))
	{
		while (pipex->path[i])
		{
			aux1 = ft_strjoin(pipex->path[i], pipex->cmd_1[0]);
			if (!pipex->expath && !access(aux1, X_OK))
				pipex->expath = ft_strdup(aux1);
			free (aux1);
			aux2 = ft_strjoin(pipex->path[i], pipex->cmd_2[0]);
			if (!pipex->expath2 && !access(aux2, X_OK))
				pipex->expath2 = ft_strdup(aux2);
			free (aux2);
			i++;
		}
	}
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
			pipex->path = ft_split(ft_strchr2(env[i], '='), ':');
		pipex->env[i] = ft_strdup(env[i]);
		i++;
	}
	pipex->env[i] = NULL;
	if (!pipex->path)
		return (NULL);
	return (pipex->env);
}

void	get_commands(char **argv, t_pipex *pipex)
{
	pipex->cmd_1 = ft_split(argv[2], ' ');
	pipex->cmd_2 = ft_split(argv[3], ' ');
	if (!pipex->cmd_1 || !pipex->cmd_2)
	{
		perror("pipex");
		exit (errno);
	}
	if (!access(pipex->cmd_1[0], X_OK))
		pipex->expath = ft_strdup(pipex->cmd_1[0]);
	if (!access(pipex->cmd_2[0], X_OK))
		pipex->expath2 = ft_strdup(pipex->cmd_2[0]);
}
