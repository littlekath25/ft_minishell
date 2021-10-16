/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/01 13:41:05 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/10/16 13:56:39 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <signal.h>

void	reprompt(int i)
{
	(void)i;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	static_func(int i)
{
	(void)i;
	printf("\n");
}

void	quit(int i)
{
	(void)i;
	printf("Quit: 3\n");
}

void	activate_signals(void)
{
	signal(SIGINT, reprompt);
	signal(SIGQUIT, SIG_IGN);
}

void	deactivate_signals(void)
{
	signal(SIGINT, static_func);
	signal(SIGQUIT, quit);
}
