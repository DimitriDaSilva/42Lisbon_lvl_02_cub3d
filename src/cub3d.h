/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:33:13 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/23 18:40:27 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
** Forbiddent external libraries to delete
*/

# include <string.h>
# include <stdio.h>

/*
** External libraries
*/

# include <fcntl.h>
# include <math.h>
# include <stdint.h>

/*
** Static libraries
*/

# include "../../libft/src/libft.h"
# include "../../libmlx/mlx.h"

/*
** Header files
*/

# include "structs.h"
# include "constants.h"
# include "utils_others.h"
# include "utils_graph.h"
# include "utils_rays.h"

void	get_scene(int fd, t_scene *scene);
void	check_scene(t_scene *scene);
void	render_game(t_game *game);

#endif