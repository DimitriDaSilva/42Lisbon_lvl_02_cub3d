/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_graph.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:44:53 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/06 17:33:43 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_GRAPH_H
# define UTILS_GRAPH_H

# include "cub3d.h"

void	draw_rect(t_rect *rect, int	*img, int res_width);
void	draw_rect_texture(t_rect *rect, int *img, t_res *res, t_ray *ray);
int		get_bitmap_offset(t_ray *ray, int bitmap_width);
void	draw_circle(t_circle *circle, int color, int *img, int res_width);
void	draw_line(t_line *line, int *img, int res_width);

#endif
