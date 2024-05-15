/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 08:25:11 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/15 15:07:54 by mfaoussi         ###   ########.fr       */
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

// int	main(int argc, char **argv, char **environ)
// {
// 	t_env	*en;

// 	en = ft_get_env(environ);
// 	while (en)
// 	{
// 		printf("%s\n",en->content[0]);
// 		en = en->next;
// 	}
// 	// env(en);
// 	// printf("current working directory : ");
// 	// pwd();
// 	// printf("deleting USER from env \n\n");
// 	// // unset(&en, "PATH");
// 	// export(&en, "sabo=brother");
// 	// export(&en, "sabo=ace");
// 	// export(&en, "TERM=luffyXXX");
// 	// env(en);
	
// 	return (0);
// }
