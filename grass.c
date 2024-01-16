/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grass.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:59:16 by ssottori          #+#    #+#             */
/*   Updated: 2024/01/16 19:42:00 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

int main(void) {
    void *mlx;
    void *mlx_win;
    void *grass;  // grass tile image here
    int width, height;  // Declare width and height variables
    int x, y;  // Declare x and y variables
	int	tile_size = 32;
	int	tiley, tilex;

    // Initialize MiniLibX
    mlx = mlx_init();

    // Create a window
    mlx_win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Grass!!!");

    // Load your grass tile image
    grass = mlx_xpm_file_to_image(mlx, "Grass.xpm", &width, &height);

    // Calculate the position to center the tile
    tilex = WIN_WIDTH / tile_size;
    tiley = WIN_HEIGHT / tile_size;

	y = 0;
	while (y < tiley * tile_size)
	{
		x = 0;
		while (x < tilex * tile_size)
		{
			mlx_put_image_to_window(mlx, mlx_win, grass, x, y);
			x += tile_size;
		}
		y += tile_size;
	}

    // Draw the grass tile at the center of the window
    // mlx_put_image_to_window(mlx, mlx_win, grass, x, y);

    // Enter the event loop
    mlx_loop(mlx);

    return 0;
}

