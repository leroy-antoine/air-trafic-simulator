/*
** EPITECH PROJECT, 2025
** handle_movements.c
** File description:
** handle movements of planes
*/

#include <math.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include "../include/my_struct.h"


void modify_position(plane_t *plane, float delta_time)
{
    float progression = 0;

    for (int i = 0; plane[i].end == 0; i++) {
        if (plane[i].alive) {
            progression = plane[i].entity_time * 0.1 / plane[i].speed;
            plane[i].entity_time += delta_time;
        }
        plane[i].position = lerp_vector(plane[i].position,
            plane[i].arrival, progression);
        if (progression >= 0.90)
            plane[i].alive = false;
        sfSprite_setPosition(plane[i].plane_sprite.sprite, plane[i].position);
        sfRectangleShape_setPosition(plane[i].plane_shape, plane[i].position);
    }
}
