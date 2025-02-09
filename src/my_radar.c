/*
** EPITECH PROJECT, 2025
** my_radar.c
** File description:
** my radar
*/

#include <stdio.h>
#include <time.h>
#include <SFML/Graphics.h>
#include "../include/my.h"
#include "../include/my_struct.h"

static void destroy_everything(sfRenderWindow *window,
    plane_t *plane, tower_t *tower, sfClock *clock)
{
    for (int i = 0; plane[i].end == 0; i++) {
        sfSprite_destroy(plane[i].plane_sprite.sprite);
        sfTexture_destroy(plane[i].plane_sprite.texture);
        sfRectangleShape_destroy(plane[i].plane_shape);
    }
    for (int i = 0; tower[i].end == 0; i++) {
        sfSprite_destroy(tower[i].tower_sprite.sprite);
        sfTexture_destroy(tower[i].tower_sprite.texture);
        sfCircleShape_destroy(tower[i].tower_shape);
    }
    sfClock_destroy(clock);
    sfRenderWindow_destroy(window);
}

static void display_things(sfRenderWindow *window, sprite_t *create_background,
    plane_t *plane, tower_t *tower)
{
    sfRenderWindow_drawSprite(window, create_background->sprite, NULL);
    for (int i = 0; plane[i].end == 0; i++) {
        if (plane[i].alive) {
            sfRenderWindow_drawSprite(window,
                plane[i].plane_sprite.sprite, NULL);
            sfRenderWindow_drawRectangleShape(window,
                plane[i].plane_shape, NULL);
        }
    }
    for (int i = 0; tower[i].end == 0; i++) {
        sfRenderWindow_drawSprite(window,
            tower[i].tower_sprite.sprite, NULL);
        sfRenderWindow_drawCircleShape(window, tower[i].tower_shape, NULL);
        }
}

static void game_loop(sfRenderWindow *window, sprite_t *create_background,
    plane_t *plane, tower_t *tower)
{
    sfClock *clock = sfClock_create();
    float delta_time;
    float elapsed_time = 0;

    while (sfRenderWindow_isOpen(window)) {
        delta_time = (float) sfClock_getElapsedTime(clock).microseconds
        / 1000000.0;
        if (delta_time < 0.01) {
            continue;
        }
        elapsed_time += delta_time;
        modify_position(plane, delta_time);
        display_things(window, create_background, plane, tower);
        sfRenderWindow_display(window);
        handle_event(window);
        sfClock_restart(clock);
    }
    destroy_everything(window, plane, tower, clock);
}

int my_radar(plane_t *plane, tower_t *tower)
{
    sprite_t create_background = {0};
    int error_background = 0;
    sfRenderWindow *window = create_window();

    if (!window)
        return ERROR;
    error_background = handle_sprite(plane, tower,
        &create_background, error_background);
    if (error_background == ERROR)
        return ERROR;
    game_loop(window, &create_background, plane, tower);
    return SUCCESS;
}
