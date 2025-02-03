/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:31:26 by braugust          #+#    #+#             */
/*   Updated: 2025/02/03 09:36:19 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char *get_cmd_path(char *cmd, char **env)
{
    char **path_tab;
    char *found_path;
    int i;
    
    i = 0;
    path_tab = NULL;
    while (env[i])
    {
        if (ft_strncmp(env[i], "PATH=", 5) == 0)
        {
            path_tab = ft_split(env[i] + 5, ':');
            break;
        }
        i++;
    }
    if (!path_tab)
    {
        fprintf(stderr, "PATH n'a pas été trouvé\n");
        return (NULL);
    }
    found_path = find_cmd(path_tab, cmd);
    free_tab(path_tab);
    return (found_path);
}

char *find_cmd(char **paths, char *cmd)
{
    int i;
    char *file;

    i = 0;
    while (paths[i])
    {
        file = ft_strjoin_path(paths[i], cmd);
        if (!file)
            return (NULL);
        if (access(file, X_OK) == 0)
            return (file);
        free(file);
        i++;
    }
    return (NULL);
}

void ft_putstr_fd(char *str, int fd)
{
    if (!str)
        return;
    write(fd, str, ft_strlen(str));
}

char *ft_strjoin_path(char *path, char *cmd)
{
    size_t lenpath;
    size_t lencmd;
    char *joined;

    lencmd = ft_strlen(cmd);
    lenpath = ft_strlen(path);
    joined = malloc(lencmd + lenpath + 2);
    if (!joined)
        return (NULL);
    ft_strcpy(joined, path);
    joined[lenpath] = '/';
    ft_strcpy(joined + lenpath + 1, cmd);
    return (joined);
}
