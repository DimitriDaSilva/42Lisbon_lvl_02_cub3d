/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_game_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:40:31 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/23 18:59:58 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ready_game_events.h"

/*
** Function that sets the event hooks. Only called once and after the window
** has been created
** @param:	- [t_game *] root struct
** Line-by-line comments:
** @1-2		No window created in "SAVE" mode so return
** @3		By the default x11 press key events are on autorepeat mode (i.e.
**			pressing a key will alternatively fire off press and release
**			events)
** @4-5		1L << 0 and 1L << 1 are X11 masks
**			(https://harm-smits.github.io/42docs/libs/minilibx/events.html)
** @6		Client message event is fired off when the user is trying to close
**			the window (ALT+F4 or window cross)
*/

void	ready_game_events(t_game *game)
{
	if (!ft_strcmp(game->mode, "SAVE"))
		return ;
	mlx_do_key_autorepeatoff(game->mlx.mlx_ptr);
	mlx_hook(game->mlx.win, KEY_PRESS, 1L << 0, key_pressed, game);
	mlx_hook(game->mlx.win, KEY_RELEASE, 1L << 1, key_released, game);
	mlx_hook(game->mlx.win,
			CLIENT_MESSAGE,
			0L,
			close_window_cross,
			game);
}

/*
** Function called whenever a key is pressed
** @param:	- [int] keycode of the key press
**			- [t_game *] param passed to that function
** @return:	[int] returns int to fit pointer function prototype
*/

int		key_pressed(int keycode, t_game *game)
{
	if (keycode == K_W)
		game->player.walk_direction = 'w';
	else if (keycode == K_A)
		game->player.walk_direction = 'a';
	else if (keycode == K_S)
		game->player.walk_direction = 's';
	else if (keycode == K_D)
		game->player.walk_direction = 'd';
	else if (keycode == K_LEFT_ARROW)
		game->player.turn_direction = -1;
	else if (keycode == K_RIGHT_ARROW)
		game->player.turn_direction = 1;
	else if (keycode == K_ESC)
		exit(EXIT_SUCCESS);
	return (1);
}

/*
** Function called whenever a key is released
** @param:	- [int] keycode of the key press
**			- [t_game *] param passed to that function
** @return:	[int] returns int to fit pointer function prototype
*/

int		key_released(int keycode, t_game *game)
{
	(void)game;
	if (keycode == K_W || keycode == K_A || keycode == K_S || keycode == K_D)
		game->player.walk_direction = 0;
	else if (keycode == K_LEFT_ARROW || keycode == K_RIGHT_ARROW)
		game->player.turn_direction = 0;
	return (1);
}

/*
** Function called whenever the user tried to close the window (ALT FT or
** window cross)
** @param:	- [int] keycode of the key press
**			- [t_game *] param passed to that function
** @return:	[int] returns int to fit pointer function prototype
*/

int		close_window_cross(int keycode, t_game *game)
{
	(void)game;
	(void)keycode;
	exit(EXIT_SUCCESS);
	return (1);
}