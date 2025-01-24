/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:23:28 by braugust          #+#    #+#             */
/*   Updated: 2025/01/24 03:45:23 by braugust         ###   ########.fr       */
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
    return 0;
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
char    *ft_strjoin_path(char *path, char *cmd)
{
    size_t  lenpath;
    size_t  lencmd;
    char    *tab;

    lencmd = ft_strlen(cmd);
    lenpath = ft_strlen(path);
    
    tab = malloc(lencmd + lenpath + 2);
    if (!tab)
        return (NULL);
    ft_strcpy(tab, path);
    tab[lenpath] = '/';
    ft_strcpy(tab + lenpath + 1, cmd);
    return (tab);
}

char    *find_cmd(char **paths, char *cmd)
{
    int     i;
    char    *files;

    i = 0;
    while (paths[i])
    {
        files = ft_strjoin_path(paths[i], cmd);
        if (!files)
            return (NULL);
        if (access(files, X_OK) == 0)
            return (files);
        free(files);
        i++;
    }
    return (NULL);
}

int main(int ac, char **av, char **env)
{
    int     i;
    char    **tab;
    char    *cmd;
    char    *foundpath;
    
    i = -1;
    tab = NULL;
    cmd = av[1];
    while (ac == 2)
    {
        if (!env)
            return (1);
        while (*env)
        {
            if(ft_strncmp(*env, "PATH=", 5) == 0)
            {
                tab = ft_split(*env + 5, ':');
                if (!tab)
                    return (1);
                break;
            }
            env++;
        }
        if (!tab)
            return (1);
        foundpath = find_cmd(tab, cmd);
        if (foundpath)
        {
            printf("Cmd found: '%s' path : %s\n", cmd, foundpath);
            free(foundpath);
        }
        else
            printf("False\n");
        while (tab[++i])
        {
            ft_putstr_fd(tab[i], 1);
            write(1, "\n", 1);
        }
        return(free_tab(tab), 0);
    }
    return(0);
}
