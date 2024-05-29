/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:00:18 by anamieta          #+#    #+#             */
/*   Updated: 2024/05/29 18:53:16 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	n_flag(char *cmd)
{
	int	i;

	i = 2;
	if (cmd[0] != '-')
		return (0);
	i = 1;
	while (cmd[i])
	{
		if (cmd[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	next_cmd_check(char *next_cmd, int nflag)
{
	if (next_cmd != NULL)
		printf(" ");
	else if (nflag != 1)
		printf("\n");
}

int	echo(char **cmd)
{
	int	start_idx;
	int	nflag;

	start_idx = 1;
	nflag = 0;
	if (cmd[start_idx] == NULL)
		printf("\n");
	if (cmd[start_idx])
		nflag = n_flag(cmd[start_idx]);
	if (nflag == 1)
	{
		printf("");
		if (cmd[start_idx + 1] != NULL)
			start_idx++;
		else
			return (EXIT_SUCCESS);
	}
	while (cmd[start_idx] != NULL)
	{
		printf("%s", cmd[start_idx]);
		next_cmd_check(cmd[start_idx + 1], nflag);
		start_idx++;
	}
	return (EXIT_SUCCESS);
}
