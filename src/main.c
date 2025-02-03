/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:23:28 by braugust          #+#    #+#             */
/*   Updated: 2025/02/03 09:32:27 by braugust         ###   ########.fr       */
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

int main(int ac, char **av, char **env)
{
    int fd_in, fd_out;
    int pipefd[2];
    pid_t pid1, pid2;
    t_pipe pipe_struct;

    if (ac != 5)
    {
        fprintf(stderr, "Usage: %s infile cmd1 cmd2 outfile\n", av[0]);
        exit(EXIT_FAILURE);
    }
    fd_in = open(av[1], O_RDONLY);
    if (fd_in < 0)
    {
        perror("open infile");
        exit(EXIT_FAILURE);
    }
    fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_out < 0)
    {
        perror("open outfile");
        close(fd_in);
        exit(EXIT_FAILURE);
    }
    if (pipe(pipefd) < 0)
    {
        perror("pipe");
        close(fd_in);
        close(fd_out);
        exit(EXIT_FAILURE);
    }
    pipe_struct.read = pipefd[0];
    pipe_struct.write = pipefd[1];
    pid1 = fork();
    if (pid1 < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid1 == 0)
        child_process1(av, env, fd_in, &pipe_struct);
    
    pid2 = fork();
    if (pid2 < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid2 == 0)
        child_process2(av, env, fd_out, &pipe_struct);
    close(fd_in);
    close(fd_out);
    close(pipefd[0]);
    close(pipefd[1]);
    
    while (wait(NULL) > 0)
        ;
    
    return 0;
}
