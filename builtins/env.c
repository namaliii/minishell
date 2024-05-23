/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 08:25:11 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/23 11:41:57 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_get_env(char **env)
{
	t_env	*lst;
	t_env	*new;
	int		i;
	char	*str;
	char	**var_value;

	lst = NULL;
	if (!env || !*env)
		printf("get environment yourself\n");
	else
	{
		i = 0;
		while (env[i])
		{
			str = ft_strdup(env[i]);
			var_value = ft_split(str, '=');
			new = env_new(var_value);
			env_add_back(&lst, new);
			free(str);
			i++;
		}
	}
	return (lst);
}

void	env(t_env	*env)
{
	t_env	*i;

	i = env;
	if (!i)
	{
		printf("no env found\n");
		return ;
	}
	while (i)
	{
		printf("%s=%s\n",i->content[0], i->content[1]);
		i = i->next;
	}
}
void	clean_env(t_shell *shell)
{
	t_env	*env;

	if (!shell)
		return ;
	while (shell->env)
	{
		env = shell->env;
		if (shell->env)
			shell->env = shell->env->next;
		if (env)
		{
			env->next = NULL;
			env->prev = NULL;
			clean_array(env->content);
			free(env);
		}
	}

}