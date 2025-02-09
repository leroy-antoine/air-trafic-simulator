/*
** EPITECH PROJECT, 2025
** handle_sprite.c
** File description:
** handle sprites
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../include/my_struct.h"
#include "../lib/my/my.h"

sfCircleShape *set_circle_shape(tower_t *tower, int ID)
{
    tower[ID].tower_shape = sfCircleShape_create();
    sfCircleShape_setPosition(tower[ID].tower_shape, tower[ID].position);
    sfCircleShape_setRadius(tower[ID].tower_shape, tower[ID].radius);
    sfCircleShape_setOutlineThickness(tower[ID].tower_shape, 1);
    sfCircleShape_setOutlineColor(tower[ID].tower_shape, sfRed);
    sfCircleShape_setFillColor(tower[ID].tower_shape, sfTransparent);
    return tower[ID].tower_shape;
}

sfRectangleShape *set_rect_shape(sfRectangleShape *plane_shape,
    sfVector2f position)
{
    sfVector2f size = {0};

    size.x = SIZE;
    size.y = SIZE;
    plane_shape = sfRectangleShape_create();
    sfRectangleShape_setPosition(plane_shape, position);
    sfRectangleShape_setSize(plane_shape, size);
    sfRectangleShape_setOutlineThickness(plane_shape, 1);
    sfRectangleShape_setOutlineColor(plane_shape, sfRed);
    sfRectangleShape_setFillColor(plane_shape, sfTransparent);
    return plane_shape;
}

static void destroy_sprites(sprite_t *destroy_sprite)
{
    sfSprite_destroy(destroy_sprite->sprite);
    sfTexture_destroy(destroy_sprite->texture);
}

static int set_sprite(char *filename, sprite_t *create_sprite)
{
    create_sprite->texture = sfTexture_createFromFile(filename, NULL);
    if (!create_sprite->texture)
        return ERROR;
    create_sprite->sprite = sfSprite_create();
    sfSprite_setTexture(create_sprite->sprite, create_sprite->texture, sfTrue);
    return SUCCESS;
}

static int set_tower_sprite(tower_t *tower)
{
    int error = SUCCESS;
    sfVector2f size = {0};

    size.x = SIZEy;
    size.y = SIZEx;
    for (int i = 0; tower[i].end == 0; i++) {
        error = set_sprite(TOWER, &tower[i].tower_sprite);
        if (error == ERROR)
            return (tower->ID);
        sfSprite_setScale(tower[i].tower_sprite.sprite, size);
        sfSprite_setPosition(tower[i].tower_sprite.sprite, tower[i].position);
    }
    return SUCCESS;
}

static int set_plane_sprite(plane_t *plane)
{
    int error = SUCCESS;
    sfVector2f size = {0};

    size.x = SIZEx;
    size.y = SIZEx;
    for (int i = 0; plane[i].end == 0; i++) {
        error = set_sprite(PLANE, &plane[i].plane_sprite);
        if (error == ERROR)
            return (plane->ID);
        sfSprite_setScale(plane[i].plane_sprite.sprite, size);
        sfSprite_setPosition(plane[i].plane_sprite.sprite, plane[i].position);
    }
    return SUCCESS;
}

int handle_sprite(plane_t *plane, tower_t *tower, sprite_t *background,
    int handle_errors)
{
    handle_errors = set_sprite(BACKGROUND, background);
    if (handle_errors == ERROR)
        return ERROR;
    handle_errors = set_plane_sprite(plane);
    if (handle_errors != SUCCESS) {
        destroy_sprites(background);
        for (int i = 0; plane[i].ID < handle_errors; i++)
            destroy_sprites(&plane[i].plane_sprite);
        return ERROR;
    }
    handle_errors = set_tower_sprite(tower);
    if (handle_errors != SUCCESS) {
        destroy_sprites(background);
        for (int i = 0; plane[i].end == 0; i++)
            destroy_sprites(&plane[i].plane_sprite);
        for (int i = 0; plane[i].ID < handle_errors; i++)
            destroy_sprites(&tower[i].tower_sprite);
        return ERROR;
    }
    return SUCCESS;
}
