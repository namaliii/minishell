/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:02:19 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/17 22:56:41 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
			return (env->content[1]);
		env = env->next;
	}
	return (NULL);
}

char	*expand(char *str, t_shell *shell)
{
	t_char	*new;
	char	*expanded;
	int		i;

	i = 0;
	if (!str || *str == '\0')
		return (NULL);
	while (str[i])
	{
		if (str[i] == '"')
			handle_db_quotes(&i, str, &new, shell);
		else if (str[i] == '\'')
			handle_sg_quotes(&i, str, &new);
		else if (str[i] == '$')
			handle_dollar(&i, str, &new, shell);
		else
			handle_simple_char(&i, str, &new);
	}
	expanded = charlst_to_str(&new);
	return (expanded);
}

void	handle_db_quotes(int *i, char *str, t_char **new, t_shell *shell)
{
	*i = *i + 1;
	while (str[*i])
	{
		if (str[*i] == '"')
		{
			*i = *i + 1;
			return ;
		}
		else if (str[*i] == '$')
			handle_dollar(&i, str, new, shell);
		else
			handle_simple_char(&i, str, new);
	}
}

void	handle_simple_char(int *i, char *str, t_char **new)
{
	t_char	*node;

	node = char_new(str[*i]);
	char_add_back(new, node);
	*i = *i + 1;
}

void	handle_dollar(int *i, char *str, t_char **new, t_shell *shell)
{
	// handle end of quotes just after dollar
	// handle nb after the dollar
	// handle the dollar solo 
	// handle the dollar then
}
