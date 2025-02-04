/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:27:31 by braugust          #+#    #+#             */
/*   Updated: 2025/02/04 06:03:46 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void child_redirection(int pos, t_pipex_data *data)
{
    if (data->nb_cmd == 1)
    {
        try_dup2(data->infile, 0);
        try_dup2(data->outfile, 1);
    }
    else if (pos == 0)
    {
        try_dup2(data->infile, 0);
        try_dup2(data->pipes[0].write, 1);
    }
    else if (pos == data->nb_cmd - 1)
    {
        try_dup2(data->pipes[pos - 1].read, 0);
        try_dup2(data->outfile, 1);
    }
    else
    {
        try_dup2(data->pipes[pos - 1].read, 0);
        try_dup2(data->pipes[pos].write, 1);
    }
}

void handle_child_error(char *msg, char **args, t_pipex_data *data)
{
    write(2, msg, ft_strlen(msg));
    if (args)
        free_tab(args);
    if (data->pipes)
        free(data->pipes);
    exit(127);
}

void child_execute(t_pipex_data *data, int pos, char **argv, char **env)
{
    char *cmd;
    char **args;

    if (data->here_doc)
        cmd = argv[3 + pos];
    else
        cmd = argv[2 + pos];
    if (!cmd || !cmd[0])
        handle_child_error("Error: empty command\n", NULL, data);
    args = ft_split(cmd, ' ');
    if (!args || !args[0] || !ft_strlen(args[0]))
        handle_child_error("Error: empty command\n", args, data);
    {
        char *path = get_cmd_path(args[0], env);
        if (!path)
            handle_child_error("Command not found: ", args, data);
        free(args[0]);
        args[0] = path;
    }
    execve(args[0], args, env);
    perror("execve");
    free_tab(args);
    if (data->pipes)
        free(data->pipes);
    exit(127);
}

pid_t launch_children(t_pipex_data *data, int here_doc, char **argv, char **env)
{
    int pos = -1;
    pid_t pid;
    pid_t last_pid = 0;

    while (++pos < data->nb_cmd)
    {
        pid = fork();
        if (pid < 0)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pid == 0)
        {
            child_redirection(pos, data);
            if (data->nb_cmd > 1)
                close_all_pipes(data->nb_cmd, data->pipes);
            if (!here_doc)
                close(data->infile);
            close(data->outfile);
            child_execute(data, pos, argv, env);
        }
        last_pid = pid;
    }
    return (last_pid);
}

void clean_parent(t_pipex_data *data)
{
    int j;

    j = 0;
    close(data->infile);
    close(data->outfile);
    if (data->nb_cmd > 1)
    {
        while (j < data->nb_cmd - 1)
        {
            close(data->pipes[j].read);
            close(data->pipes[j].write);
            j++;
        }
        free(data->pipes);
    }
}
