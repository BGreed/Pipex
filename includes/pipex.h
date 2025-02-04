/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:24:07 by braugust          #+#    #+#             */
/*   Updated: 2025/02/04 05:58:55 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipe
{
    int read;
    int write;

}   t_pipe;

typedef struct s_pipex_data
{
    int     infile;
    int     outfile;
    t_pipe *pipes;
    int     nb_cmd;
    int     here_doc;
    int     outfile_valid;
    int     error; 

}   t_pipex_data;

int     ft_strncmp(const char *s1, const char *s2, size_t n);
void    free_tab(char **tab);
char    *check_paths(char **paths, char *cmd);
char    *get_cmd_path(char *cmd, char **env);
void    read_here_doc(char *limiter, int write_fd);
void    close_all_pipes(int nb_cmd, t_pipe *pipes);
void    init_files_here_doc(int argc, char **argv, t_pipex_data *data);
void    init_files_normal(int argc, char **argv, t_pipex_data *data);
void    init_files(int argc, char **argv, t_pipex_data *data);
t_pipe  *init_pipes(int nb_cmd);
void    try_dup2(int oldfd, int newfd);
void    child_redirection(int pos, t_pipex_data *data);
void    handle_child_error(char *msg, char **args, t_pipex_data *data);
void    child_execute(t_pipex_data *data, int pos, char **argv, char **env);
pid_t   launch_children(t_pipex_data *data, int here_doc, char **argv, char **env);
void    clean_parent(t_pipex_data *data);

#endif