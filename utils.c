/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 08:25:12 by fballest          #+#    #+#             */
/*   Updated: 2021/11/05 08:25:28 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

// void	ft_printerror(char *str, int error, t_pipex *pipex)
// {
// 	printf("%s\n", str);
// 	if (pipex->path)
// 		ft_freearray(pipex->path);
// 	if (pipex->path2)
// 		ft_freearray(pipex->path2);
// 	if (pipex->env)
// 		ft_freearray(pipex->env);
// 	if (pipex->cmd_1)
// 		ft_freearray(pipex->cmd_1);
// 	if (pipex->cmd_2)
// 		ft_freearray(pipex->cmd_2);
// 	free(pipex);
// 	exit(error * -1);
// }

// char	**add_slash_paths(t_pipex *pipex)
// {
// 	char	**aux;
// 	int		i;

// 	i = 0;
// 	aux = ft_calloc(sizeof(char *), i + 1);
// 	while (pipex->path[i])
// 	{
// 		aux[i] = ft_strjoin(pipex->path[i], "/");
// 		free (pipex->path[i]);
// 		i++;
// 	}
// 	free (pipex->path);
// 	aux[i] = NULL;
// 	retrun (aux);
// }

// char	**take_envs(char **env, t_pipex *pipex)
// {
// 	int		i;

// 	i = 0;
// 	if (!env)
// 		return (NULL);
// 	while (env[i])
// 		i++;
// 	pipex->env = ft_calloc(sizeof(char *), i);
// 	i = 0;
// 	while (env[i])
// 	{
// 		if (ft_strncmp(env[i], "PATH=", 5))
// 		{
// 			pipex->path = ft_split(env[i], ':');
// 			if (!pipex->path)
// 				return (NULL);
// 		}
// 		pipex->env[i] = ft_strdup(env[i]);
// 		i++;
// 	}
// 	pipex->env[i] = NULL;
// 	return (pipex->env);
// }

// void	get_commands(char **argv, t_pipex *pipex)
// {
// 	pipex->cmd_1 = ft_split(agrv[2], ' ');
// 	pipex->cmd_2 = ft_split(argv[4], ' ');
// 	if (!pipex->cmd_1 || !pipex->cmd_2)
// 		ft_printerror("Error: Not enought parameters\n", 4, pipex);
// 	else
// 		add_command_path(pipex);∫
// }

// void	check_path(t_pipex *pipex)
// {
// 	while (pipex->path[i])
// 	{
// 		if (!access(pipex->path[i], X_OK))
// 			pipex->x = i + 1;
// 		if (!access(pipex->path2[i], X_OK))
// 			pipex->y = i + 1;
// 		i++;
// 	}
// 	if (!pipex->x || !pipex->y)
// 		ft_printerror("Error: Command not found\n", 5, pipex);
// 	else
// 	{
// 		pipex->x = pipex->x - 1;
// 		pipex->y = pipex->y - 1;
// 	}
// }

// void	add_command_path(t_pipex *pipex)
// {
// 	int		i;
// 	char	**aux1;
// 	char	**aux2;

// 	i = 0;
// 	aux1 = NULL;
// 	aux2 = NULL;
// 	while (pipex->path[i])
// 		i++
// 	aux1 = ft_calloc(sizeof(char *), i);
// 	aux2 = ft_calloc(sizeof(char *), i);
// 	i = 0;
// 	while (pipex->path[i])
// 	{
// 		aux1[i] = ft_strjoin(pipex->path, pipex->cmd_1);
// 		free (pipex->path[i]);
// 		aux2[i] = ft_strjoin(pipex->path2, pipex->cmd_2);
// 		free (pipex->path2[i]);
// 	}
// 	free (pipex->path);
// 	free (pipex->path2);
// 	pipex->path = aux1;
// 	pipex->path2 = aux2;
// 	check_path(pipex);
// }

// void	open_files(char **argv, t_pipex *pipex)
// {
// 	if (!access(argv[1], R_OK) && !access(argv[3], R_OK))
// 	{
// 		pipex->fd_in = open(argv[1], O_RDONLY);
// 		pipex->fd_out = open(argv[3], O_RDWR | O_CREAT, S_IRWXU | O_APPEND);
// 	}
// 	else
// 		ft_printerror("Error: Not valid files.\n", 3, pipex);
// }

// int	main (int argc, char **argv, char **env)
// {
//     t_pipex		*pipex;

// 	pipex = ft_calloc(sizeof(t_pipex), 1);
// 	pipex->env = take_envs(env, pipex);
// 	if (!pipex || !pipex->env || argc < 5)
// 		ft_printferror("Error:\n", 1, pipex);
// 	if (argc == 5)
// 	{
// 		open_files(argv, pipex);
// 		get_commands(argv, pipex);
// 		pipex->path = add_slash_paths(pipex);
// 		add_command_path(pipex);

// 	}
// 	else
// 		ft_printerror("Error: Not enought parameters\n", 2, pipex);
// 	return (0);
// }