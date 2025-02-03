/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:24:07 by braugust          #+#    #+#             */
/*   Updated: 2025/02/03 09:29:51 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipe
{
    int read;
    int write;

}   t_pipe;

void    child_process1(char **av, char **env, int fd_in, t_pipe *pipe);
void    child_process2(char **av, char **env, int fd_out, t_pipe *pipe);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
void    free_tab(char **tab);
char    *ft_strjoin_path(char *path, char *cmd);
char    *find_cmd(char **paths, char *cmd);
void    ft_putstr_fd(char *str, int fd);
char    *get_cmd_path(char *cmd, char **env);

#endif