/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:45:25 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/30 16:56:39 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_exit_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	ft_exit(t_shell *shell, t_node *index)
{
	if (index && array_size(index->cmd) > 2)
	{
		printf("minishell: exit: too many arguments\n");
		shell->exit_code = 1;
	}
	else if (index && index->cmd[1])
	{
		if (check_exit_arg(index->cmd[1]) == 1)
		{
			printf("minishell: exit: %s: numeric argument required\n",
				index->cmd[1]);
			clean_shell(shell);
			shell->exit_code = 255;
			exit(255);
		}
		else
		{
			shell->exit_code = ft_atoi(index->cmd[1]);
			clean_shell(shell);
			exit(shell->exit_code);
		}
	}
	else
	{
		clean_shell(shell);
		exit(0);
	}
}

int	array_size(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
