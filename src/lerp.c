/*
** EPITECH PROJECT, 2025
** lerp.c
** File description:
** lerp
*/

#include <SFML/Graphics.h>
#include "../include/my_struct.h"

static float lerp(float min, float max, float progression)
{
    if (progression > 1 || progression < 0)
        return (float) ERROR;
    return min + (max - min) * progression;
}

sfVector2f lerp_vector(sfVector2f begin, sfVector2f end, float progression)
{
    return (sfVector2f) {
        lerp(begin.x, end.x, progression),
        lerp(begin.y, end.y, progression)
    };
}
