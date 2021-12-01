/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:01:14 by fballest          #+#    #+#             */
/*   Updated: 2021/12/01 15:47:59 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*
**LIBRARIES
*/
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

/*
**WORKING STRUCTURES
*/
typedef struct s_pipex
{
	int		x;
	int		y;
	int		fd_in;
	int		fd_out;
	char	*file_in;
	char	*file_out;
	char	**cmd_1;
	char	**cmd_2;
	char	**env;
	char	**path;
	char	*expath;
	char	*expath2;
	pid_t	ph;
}				t_pipex;

/*
**FILES AND FUNTIONS
*/
/*
**PIPEXMAIN.C
*/
void		open_files(char **argv, t_pipex *pipex);
void		execute_fork2(int *fd, t_pipex *pipex);
void		init_pipe(t_pipex *pipex, int *fd);
void		execute_fork(t_pipex *pipex);
int			main(int argc, char **argv, char **env);

/*
**PARSER.C
*/
char		**add_slash_paths(t_pipex *pipex);
void		add_command_bucle(t_pipex *pipex, int *i);
void		add_command_path(t_pipex *pipex);
char		**take_envs(char **env, t_pipex *pipex);
void		get_commands(char **argv, t_pipex *pipex);

/*
**UTILS_LIBFT.C
*/
void		*ft_calloc(size_t count, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_matrixlines(char **str);

/*
**UTILS_LIBFT_B.C AND 3 STATIC FUNTIONS
*/
char		**ft_split(const char *s, char c);
void		ft_matrixfree(char **str);

/*
**UTILS_LIBFT_C.C
*/
char		*ft_strchr2(const char *str, char c);
size_t		ft_strlen(const char *str);
void		ft_bzero(void *str, size_t n);
void		freememory(t_pipex *pipex);

#endif
