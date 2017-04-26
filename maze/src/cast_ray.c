#include "maze.h"
#include <stdlib.h>

/* Draw the maze */
int *cast_ray(int ray_angle, Player_POV *player, char *map[MAP_WIDTH][MAP_HEIGHT])
{
    static int coords[2];
    int found_horizontal_coords;
    int horizontal_coords[2] = {5, 4};

    /* Debugging: */
    if (HIDE_INFO) {
        printf("Player x: %i\n", player->x_coord);
        printf("Player y: %i\n", player->y_coord);
        printf("Player angle: %i\n", player->angle);
        printf("char: %s\n", map[0][0]);
        printf("ray angle: %i\n", ray_angle);
    } else if (DEBUG) {
        printf("%s\n", "====== CAST_RAY =====");
    }

    /* do mathy things and calculate length of line to draw) */
    found_horizontal_coords = check_horizontal_intersections(horizontal_coords,
        ray_angle, player, map);
    if (!found_horizontal_coords) {
        printf("%s\n", "NO HORIZONTAL COORDS");
    } else {
        printf("horizontal_coords y: %i\n", horizontal_coords[1]);
        printf("horizontal_coords x: %i\n", horizontal_coords[0]);
    }

    /*
    vertical_coords = check_vertical_intersections(ray_angle, player, map);
    return whichever coords are closer
    */

    /* if ((column_i >= 0 && column_i <= 40) ||
        (column_i >= (WINDOW_WIDTH - 40) && column_i <= (WINDOW_WIDTH)))
    {
        coords[0] = 0;
        coords[1] = 0;
    }
    else
    {
        coords[0] = WINDOW_HEIGHT / 4;
        coords[1] = WINDOW_HEIGHT / 4 * 3;
    } */


    return coords;
}