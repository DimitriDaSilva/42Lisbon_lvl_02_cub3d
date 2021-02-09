/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:18:45 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/08 19:46:41 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_SPRITES_H
# define DRAW_SPRITES_H

# include "cub3d.h"

void	adjust_sprite_pos(t_ray *ray);
void	get_sprite_distances(t_ray *ray, t_player *player);
void	sort_sprites(t_ray *ray);
void	draw_sprite_strip(t_game *game, t_ray *ray);

#endif
