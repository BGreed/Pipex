/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:31:26 by braugust          #+#    #+#             */
/*   Updated: 2025/02/04 06:02:45 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


char	*check_paths(char **paths, char *cmd)
{
	char	*tmp;
	int		i;
	int		len;

    i = 0;
	while (paths[i])
	{
		len = ft_strlen(paths[i]) + ft_strlen(cmd) + 2;
		tmp = malloc(len);
		if (!tmp)
			return (NULL);
		ft_strcpy(tmp, paths[i]);
		ft_strcpy(tmp + ft_strlen(paths[i]), "/");
		ft_strcpy(tmp + ft_strlen(paths[i]) + 1, cmd);
		if (access(tmp, X_OK) == 0)
			return (tmp);
		free(tmp);
		i++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **env)
{
	char	**paths;
	char	*ret;
	int		i;

    i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (NULL);
	paths = ft_split(env[i] + 5, ':');
	if (!paths)
		return (NULL);
	ret = check_paths(paths, cmd);
	free_tab(paths);
	return (ret);
}
void	read_here_doc(char *limiter, int write_fd)
{
	char	line[1024];
	int		i;
	char	c;

	while (1)
	{
		i = 0;
		while (read(0, &c, 1) > 0 && c != '\n' && i < 1023)
			line[i++] = c;
		line[i] = '\0';
		if (strcmp(line, limiter) == 0)
			break;
		write(write_fd, line, ft_strlen(line));
		write(write_fd, "\n", 1);
	}
}

void	close_all_pipes(int nb_cmd, t_pipe *pipes)
{
	int	j;

    j = 0;
	while (j < nb_cmd - 1)
	{
		close(pipes[j].read);
		close(pipes[j].write);
		j++;
	}
}
