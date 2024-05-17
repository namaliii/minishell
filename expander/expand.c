/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:02:19 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/17 16:29:51 by mfaoussi         ###   ########.fr       */
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



// char	*expand(char *str)
// {
// 	char	*new;
// 	int		i;
// 	int		a;

// 	if (!str || *str == '\0')
// 		return (NULL);
// 	i = 0;
// 	a = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '$')
// 		{
			
// 		}
// 	}
// }
