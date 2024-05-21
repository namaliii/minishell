/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:24:42 by anamieta          #+#    #+#             */
/*   Updated: 2024/05/21 15:06:42 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	open_file(t_shell *shell, int type, char *file_name)
{
	int	fd;

	fd = 777;
	if (type == INFILE || type == HEREDOC)
		fd = open(file_name, O_RDONLY);
	else if (type == OUTFILE)
		fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (type == APPEND)
		fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(file_name, 2);
		ft_putstr_fd(": No such file or directory", 2);
		ft_putstr_fd("\n", 2);
		close(fd);
		shell->exit_code = 127;
		exit(127);
	}
	return (fd);
}

int	open_file_hd(t_shell *shell, int type, char *file_name)
{
	int	fd;

	fd = 777;
	if (type == HEREDOC)
		fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(file_name, 2);
		ft_putstr_fd(": No such file or directory", 2);
		ft_putstr_fd("\n", 2);
		close(fd);
		shell->exit_code = 127;
		exit(127);
	}
	return (fd);
}
