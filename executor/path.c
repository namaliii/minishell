/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:32:06 by anamieta          #+#    #+#             */
/*   Updated: 2024/05/22 13:41:21 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**get_path(t_shell *shell)
{
	char	**path;
	t_env	*index;

	index = shell->env;
	while (index)
	{
		if (ft_strncmp(index->content[0], "PATH", 4) == 0)
		{
			path = ft_split(index->content[1], ':');
			return (path);
		}
		index = index->next;
	}
	return (NULL);
}
/**
 * check_cmd_path- will take a command as string if it's full path we will just
 * return it , else we will create the full path and return it
 *
*/

char	*check_cmd_path(char *cmd, char **paths)
{
	int		i;
	char	*aux;
	char	*cmd_cpy;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	i = 0;
	while (paths[i])
	{
		cmd_cpy = ft_strdup(cmd);
		aux = ft_strjoin(paths[i], "/");
		cmd_cpy = ft_strjoin(aux, cmd_cpy);
		free(aux);
		if (access(cmd_cpy, X_OK) == 0)
			return (cmd_cpy);
		free(cmd_cpy);
		i++;
	}
	return (NULL);
}

void	clean_path(t_shell *shell)
{
	clean_array(shell->path);
}

