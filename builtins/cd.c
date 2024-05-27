/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:27:29 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/27 16:23:00 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update_pwd_oldpwd(t_shell *shell, char **old_path);

void	cd(t_shell	*shell, t_node *index)
{
	char	*old_path;
	t_env	*home;

	old_path = get_pwd();
	if (!index->cmd[1])
	{
		home = point_to_env("HOME", shell);
		if (!home || home->content[1] == NULL)
			printf("no Home for me \n");
		else
		{
			if (chdir(home->content[1]) != 0)
				printf("path doesn't exist\n");
		}
	}
	else
	{
		if (chdir(index->cmd[1]) != 0)
			printf("path doesn't exist\n");
	}
	update_pwd_oldpwd(shell, &old_path);
}

void	update_pwd_oldpwd(t_shell *shell, char **old_path)
{
	char	*path;
	t_env	*pwd;
	t_env	*old_pwd;

	update_env("OLDPWD=", shell);
	pwd = point_to_env("PWD", shell);
	old_pwd = point_to_env("OLDPWD", shell);
	if (old_pwd->content[1])
		free(old_pwd->content[1]);
	old_pwd->content[1] = ft_strdup(*old_path);
	path = get_pwd();
	if (pwd)
	{
		free(pwd->content[1]);
		pwd->content[1] = path;
	}
	else
		free(path);
}
