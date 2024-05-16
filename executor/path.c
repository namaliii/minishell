/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:32:06 by anamieta          #+#    #+#             */
/*   Updated: 2024/05/16 12:28:44 by anamieta         ###   ########.fr       */
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
