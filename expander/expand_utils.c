/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:00:00 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/29 17:25:36 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_t_char_length(t_char **new)
{
	int		i;
	t_char	*index;

	if (!new || *new == NULL)
		return (0);
	index = *new;
	i = 0;
	while (index)
	{
		index = index->next;
		i++;
	}
	return (i);
}

char	*charlst_to_str(t_char **new)
{
	int		size;
	char	*expanded;
	t_char	*index;

	if (!new || !*new)
		return (NULL);
	size = get_t_char_length(new) + 1;
	expanded = malloc(sizeof(char) * size);
	if (!expanded)
		return (NULL);
	size = 0;
	while (*new)
	{
		index = *new;
		*new = (*new)->next;
		expanded[size] = index->c;
		index->next = NULL;
		free(index);
		size++;
	}
	expanded[size] = '\0';
	return (expanded);
}

void	init_tmp(char *tmp, int start, int index, char *str)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		tmp[i] = '\0';
		i++;
	}
	i = 0;
	while (start <= index)
	{
		tmp[i] = str[start];
		i++;
		start++;
	}
}

void	extract_tmp(char *tmp, t_char **new)
{
	int		i;
	t_char	*node;

	if (!tmp || tmp[0] == '\0' || !new)
		return ;
	i = 0;
	while (tmp[i])
	{
		node = char_new(tmp[i]);
		char_add_back(new, node);
		i++;
	}
}

/**
 * get_env_value will take a key and return the value if it exist in the env
 * 
*/

char	*get_env_value(t_shell *shell, char *key)
{
	t_env	*env;

	env = shell->env;
	while (env)
	{
		if (ft_strncmp(key, env->content[0], ft_strlen(key)) == 0)
		{
			if (ft_strlen(key) == ft_strlen(env->content[0]))
				return (ft_strdup(env->content[1]));
		}
		env = env->next;
	}
	return (NULL);
}
