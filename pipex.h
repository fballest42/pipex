/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:01:14 by fballest          #+#    #+#             */
/*   Updated: 2021/07/13 16:10:13 by fballest         ###   ########.fr       */
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
# include "libft/libft.h"

/*
**WORKING STRUCTURES
*/
typedef struct s_pipex
{
	int		x;
	int		y;
	char	*filein;
	char	*fileout;
}				t_pipex;

/*
**FILES AND FUNTIONS
*/
/*
**PIPEXMAIN
*/

/*
**UTILS.C
*/
void	ft_printerror(char *str, int error, t_pipex *pipex);

#endif
