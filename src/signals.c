/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/01 13:41:05 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/08/15 15:10:56 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <signal.h>

void	reprompt(int i)
{
	(void)i;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	static_func(int i)
{
	(void)i;
}

void	activate_signals(void)
{
	signal(SIGINT, reprompt);
	signal(SIGQUIT, SIG_IGN);
}

void	deactivate_signals(void)
{
	signal(SIGINT, static_func);
}
