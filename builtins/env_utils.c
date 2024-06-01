/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:41:41 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/06/01 14:45:09 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update_env(char *str, t_shell *shell)
{
	t_env	*index;
	char	*s;
	char	*key;

	key = ft_strdup2(str, get_equal_position(str));
	index = point_to_env(key, shell);
	free(key);
	if (index != NULL)
	{
		free(index->content[1]);
		s = ft_strdup(str + get_equal_position(str) + 1);
		index->content[1] = s;
		index->export = 0;
	}
	else
	{
		add_to_env(str, shell);
	}
}

void	add_to_env(char *str, t_shell *shell)
{
	char	*s1;
	char	*s2;
	char	**s;
	t_env	*new;

	s1 = ft_strdup2(str, get_equal_position(str));
	s2 = ft_strdup(str + get_equal_position(str) + 1);
	s = malloc(sizeof(char *) * 3);
	if (!s)
		return ;
	s[0] = s1;
	s[1] = s2;
	s[2] = NULL;
	new = env_new(s, 0);
	if (!new)
		return ;
	env_add_back(&(shell->env), new);
}
