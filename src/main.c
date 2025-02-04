/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:23:28 by braugust          #+#    #+#             */
/*   Updated: 2025/02/04 06:02:05 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    while (n > 0)
    {
        if (*s1 != *s2)
            return ((unsigned char)*s1 - (unsigned char)*s2);
        if (*s1 == '\0')
            return (0);
        s1++;
        s2++;
        n--;
    }
    return (0);
}

void free_tab(char **tab)
{
    int i = 0;
    while (tab[i])
        free(tab[i++]);
    free(tab);
}

int main(int argc, char **argv, char **env)
{
    t_pipex_data data;
    int status;
    pid_t last_pid;

    if (argc < 5)
    {
        write(2, "Usage:\nNormal: ./pipex file1 cmd1 ... cmdn file2\n", 47);
        write(2, "Here_doc: ./pipex here_doc LIMITER cmd1 ... cmdn file\n", 53);
        return (1);
    }
    data.error = 0;
    init_files(argc, argv, &data);
    data.pipes = init_pipes(data.nb_cmd);
    last_pid = launch_children(&data, data.here_doc, argv, env);
    clean_parent(&data);
    if (waitpid(last_pid, &status, 0) < 0)
        status = 1;
    while (wait(NULL) > 0)
        ;
    if (data.error)
        return (1);
    if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    else
        return (1);
}
