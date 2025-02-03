/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:27:31 by braugust          #+#    #+#             */
/*   Updated: 2025/02/03 09:35:25 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    child_process1(char **av, char **env, int fd_in, t_pipe *pipe)
{
    char    **cmd_args;
    char    *cmd_path;

    if (dup2(fd_in, STDIN_FILENO) < 0)
    {
        perror("dup2 infile");
        exit(EXIT_FAILURE);
    }
    if (dup2(pipe->write, STDOUT_FILENO) < 0)
    {
        perror("dup2 pipe write");
        exit(EXIT_FAILURE);
    }
    close(fd_in);
    close(pipe->write);
    close(pipe->read);

    cmd_args = ft_split(av[2], ' ');
    if (!cmd_args)
    {
        fprintf(stderr, "Erreur ft_split pour la commande: %s\n", av[2]);
        exit(EXIT_FAILURE);
    }
    cmd_path = get_cmd_path(cmd_args[0], env);
    if (!cmd_path)
    {
        fprintf(stderr, "Commande introuvable: %s\n", av[2]);
        free_tab(cmd_args);
        exit(EXIT_FAILURE);
    }
    free(cmd_args[0]);
    cmd_args[0] = cmd_path;
    execve(cmd_path, cmd_args, env);
    perror("execve cmd1");
    free_tab(cmd_args);
    exit(EXIT_FAILURE);
}

void    child_process2(char **av, char **env, int fd_out, t_pipe *pipe)
{
    char    **cmd_args;
    char    *cmd_path;

    if (dup2(pipe->read, STDIN_FILENO) < 0)
    {
        perror("dup2 pipe read");
        exit(EXIT_FAILURE);
    }
    if (dup2(fd_out, STDOUT_FILENO) < 0)
    {
        perror("dup2 outfile");
        exit(EXIT_FAILURE);
    }
    close(fd_out);
    close(pipe->read);
    close(pipe->write);

    cmd_args = ft_split(av[3], ' ');
    if (!cmd_args)
    {
        fprintf(stderr, "Erreur ft_split pour la commande: %s\n", av[3]);
        exit(EXIT_FAILURE);
    }
    cmd_path = get_cmd_path(cmd_args[0], env);
    if (!cmd_path)
    {
        fprintf(stderr, "Commande introuvable: %s\n", av[3]);
        free_tab(cmd_args);
        exit(EXIT_FAILURE);
    }
    free(cmd_args[0]);
    cmd_args[0] = cmd_path;
    execve(cmd_path, cmd_args, env);
    perror("execve cmd2");
    free_tab(cmd_args);
    exit(EXIT_FAILURE);
}
