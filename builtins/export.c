/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:58:43 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/06/01 14:42:22 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_export(char *str, int length)
{
	int	i;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	if (ft_isalpha(str[i]) == 0 && str[i] != '_')
		return (1);
	else
		i++;
	while (str[i] && i < length)
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

void	export(t_shell *shell, t_node *index)
{
	int	i;
	int	equal;

	i = 1;
	if (index->cmd[1] == NULL)
		exp_print(shell->env);
	while (index->cmd[i])
	{
		if (check_equal(index->cmd[i]) == 0)
			export_solo(index->cmd[i], shell);
		else
		{
			equal = get_equal_position(index->cmd[i]);
			if (equal == 0)
				print_export_error(index->cmd[i]);
			else
			{
				if (check_export(index->cmd[i], equal) == 1)
					print_export_error(index->cmd[i]);
				else
					update_env(index->cmd[i], shell);
			}
		}
		i++;
	}
}

void	export_solo(char *key, t_shell *shell)
{
	if (check_export(key, ft_strlen(key)) == 1)
		print_export_error(key);
	else
	{
		add_to_env_solo(key, shell);
	}
}

t_env	*point_to_env(char *key, t_shell *shell)
{
	t_env	*env;

	env = shell->env;
	while (env)
	{
		if (ft_strncmp(key, env->content[0], ft_strlen(key)) == 0)
		{
			if (ft_strlen(key) == ft_strlen(env->content[0]))
				return (env);
		}
		env = env->next;
	}
	return (NULL);
}

void	add_to_env_solo(char *str, t_shell *shell)
{
	t_env	*index;
	char	*s1;
	char	**s;

	index = NULL;
	index = point_to_env(str, shell);
	if (index)
		return ;
	s = malloc(sizeof(char *) * 3);
	s1 = ft_strdup(str);
	s[0] = s1;
	s[1] = NULL;
	s[2] = NULL;
	index = env_new(s, 1);
	if (!index)
		return ;
	env_add_back(&(shell->env), index);
}
