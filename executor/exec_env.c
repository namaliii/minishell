/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:43:20 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/25 12:54:53 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**exec_env(t_shell *shell)
{
	char	**env;
	int		i;
	t_env	*s_env;

	if (!shell || !shell->env)
		return (NULL);
	s_env = shell->env;
	env = malloc(sizeof(char *) * (get_t_env_length(s_env) + 1));
	if (!env)
		return (NULL);
	i = 0;
	while (s_env)
	{
		env[i] = get_char_env_line(s_env);
		i++;
		s_env = s_env->next;
	}
	env[i] = NULL;
	return (env);
}

char	*get_char_env_line(t_env *s_env)
{
	char	*str;
	char	*str2;

	if (!s_env || !s_env->content || !s_env->content[0])
		return (NULL);
	str = ft_strdup(s_env->content[0]);
	str2 = ft_strjoin(str, "=");
	free(str);
	if (s_env->content[1])
	{
		str = ft_strjoin(str2, s_env->content[1]);
		free(str2);
		return (str);
	}
	else
		return (str2);
}

int	get_t_env_length(t_env *env)
{
	int i;
	t_env *index;

	if (!env)
		return (0);
	index = env;
	i = 0;
	while (index)
	{
		index = index->next;
		i++;
	}
	return (i);
}
