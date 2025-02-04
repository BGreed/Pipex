/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 06:01:28 by braugust          #+#    #+#             */
/*   Updated: 2025/02/04 06:02:25 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    init_files_here_doc(int argc, char **argv, t_pipex_data *data)
{
    int here_pipe[2];

    data->here_doc = 1;
    data->nb_cmd = argc - 4;
    if (pipe(here_pipe) < 0)
    {
        perror("pipe here_doc");
        exit(EXIT_FAILURE);
    }
    read_here_doc(argv[2], here_pipe[1]);
    close(here_pipe[1]);
    data->infile = here_pipe[0];
    data->outfile = open(argv[argc - 1],
            O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (data->outfile < 0)
    {
        perror("open outfile");
        data->outfile = open("/dev/null", O_WRONLY);
        data->error = 1;
    }
}

void init_files_normal(int argc, char **argv, t_pipex_data *data)
{
    data->here_doc = 0;
    data->nb_cmd = argc - 3;
    data->infile = open(argv[1], O_RDONLY);
    if (data->infile < 0)
    {
        perror("open infile");
        data->infile = open("/dev/null", O_RDONLY);
    }
    data->outfile = open(argv[argc - 1],
            O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (data->outfile < 0)
    {
        perror("open outfile");
        data->outfile = open("/dev/null", O_WRONLY);
        data->error = 1;
    }
}

void init_files(int argc, char **argv, t_pipex_data *data)
{
    data->error = 0;
    if (ft_strncmp(argv[1], "here_doc", 8) == 0)
        init_files_here_doc(argc, argv, data);
    else
        init_files_normal(argc, argv, data);
}

t_pipe *init_pipes(int nb_cmd)
{
    t_pipe *pipes;
    int     i; 
    int     p[2];

    i = -1;
    if (nb_cmd <= 1)
        return (NULL);
    pipes = malloc((nb_cmd - 1) * sizeof(t_pipe));
    if (!pipes)
    {
        perror("malloc pipes");
        exit(EXIT_FAILURE);
    }
    while (++i < nb_cmd - 1)
    {
        if (pipe(p) < 0)
        {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
        pipes[i].read = p[0];
        pipes[i].write = p[1];
    }
    return (pipes);
}

void try_dup2(int oldfd, int newfd)
{
    if (dup2(oldfd, newfd) < 0)
        exit(EXIT_FAILURE);
}
