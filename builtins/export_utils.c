/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:57:18 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/27 17:09:40 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_export_error(char *str)
{
	printf("export: \'%s\': not a valid identifier\n", str);
}

int	get_equal_position(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (0);
}

int	check_equal(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	check_export_error(char *str)
{
	if (check_export(str, ft_strlen(str)) == 1)
		print_export_error(str);
}

// if (check_export(index->cmd[i], ft_strlen(index->cmd[i])) == 1)
				// print_export_error(index->cmd[i]);