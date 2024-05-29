/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:58:43 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/29 18:19:34 by mfaoussi         ###   ########.fr       */
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
		printf("export whatever\n");
	while (index->cmd[i])
	{
		if (check_equal(index->cmd[i]) == 0)
			check_export_error(index->cmd[i]);
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
	new = env_new(s);
	if (!new)
		return ;
	env_add_back(&(shell->env), new);
}

// int main(void)
// {
// 	printf("%d\n",check_export("Hell"));
// 	printf("%d\n",check_export("*hraven"));
// 	printf("%d\n",check_export("_HELL"));
// 	printf("%d\n",check_export("-heaven"));
// 	printf("%d\n",check_export("h311"));
// 	printf("%d\n",check_export("h&eaven"));
// 	printf("%d\n",check_export("__h"));
// 	printf("%d\n",check_export("3h"));
// 	return (0);
// }
