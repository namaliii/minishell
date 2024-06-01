/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:56:26 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/06/01 15:53:34 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	setup_signals(void)
{
	struct sigaction	sa_sigint;
	struct termios		termios_settings;

	sa_sigint = (struct sigaction){};
	tcgetattr(0, &termios_settings);
	termios_settings.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &termios_settings);
	sa_sigint.sa_handler = parent_signals;
	sigaction(SIGINT, &sa_sigint, NULL);
	signal(SIGQUIT, SIG_IGN);
}
