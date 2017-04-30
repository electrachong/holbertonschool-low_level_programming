#include "maze.h"
#include <stdlib.h>

/* Draw the maze */
int *cast_ray(int ray_angle, Player_POV *player, char (*map)[MAP_WIDTH])
{
    int coords[0];
    int found_horizontal_coords;
    int horizontal_coords[2] = {5, 4};
    int found_vertical_coords;
    int vertical_coords[2] = {2, 3};
    int x_diff;
    int y_diff;
    int distance;
    int distance_to_horizontal_coord;
    int distance_to_vertical_coord;
    /* Debugging: */
    if (HIDE_INFO) {
        printf("Player x: %i\n", player->x_coord);
        printf("Player y: %i\n", player->y_coord);
        printf("Player angle: %i\n", player->angle);
        printf("char: %c\n", map[0][0]);
        printf("ray angle: %i\n", ray_angle);
    } else if (DEBUG) {
        printf("%s\n", "====== CAST_RAY START =====");
    }

    /* do mathy things and calculate length of line to draw) */
    found_horizontal_coords = check_horizontal_intersections(horizontal_coords,
        ray_angle, player, map);
    found_vertical_coords = check_vertical_intersections(vertical_coords,
        ray_angle, player, map);

    if (DEBUG) {
        if (!found_horizontal_coords) {
            printf("%s\n", "NO HORIZONTAL COORDS");
        } else {
            printf("horizontal_coords x: %i\n", horizontal_coords[0]);
            printf("horizontal_coords y: %i\n", horizontal_coords[1]);
        }
        if (!found_vertical_coords) {
            printf("%s\n", "NO VERTICAL COORDS");
        } else {
            printf("vertical_coords x: %i\n", vertical_coords[0]);
            printf("vertical_coords y: %i\n", vertical_coords[1]);
        }
    }

    if (!found_horizontal_coords && !found_vertical_coords) {
        coords[0] = 0;
        coords[1] = 0;
        return coords; /* not no distance, but no wall for ray */
    } else if (found_horizontal_coords && !found_vertical_coords) {
        x_diff = (player->x_coord - horizontal_coords[0]);
        y_diff = (player->y_coord - horizontal_coords[1]);
        distance = sqrt(x_diff * x_diff + y_diff * y_diff);
        /* calculate distance for horizontal coords & return */
    } else if (!found_horizontal_coords && !found_vertical_coords) {
        x_diff = (player->x_coord - vertical_coords[0]);
        y_diff = (player->y_coord - vertical_coords[1]);
        distance = sqrt(x_diff * x_diff + y_diff * y_diff);
        /* calculate distance for vertical coords & return */
    } else {
        x_diff = (player->x_coord - horizontal_coords[0]);
        y_diff = (player->y_coord - horizontal_coords[1]);
        distance_to_horizontal_coord = sqrt(x_diff * x_diff + y_diff * y_diff);
        x_diff = (player->x_coord - vertical_coords[0]);
        y_diff = (player->y_coord - vertical_coords[1]);
        distance_to_vertical_coord = sqrt(x_diff * x_diff + y_diff * y_diff);
        if (distance_to_horizontal_coord < distance_to_vertical_coord) {
            distance = distance_to_horizontal_coord;
        } else {
            distance = distance_to_vertical_coord;
        }
        /* compare distances and return the closer one */
    }

    printf("%s\n", "====== CAST_RAY END =====");
    return coords;
}
