/*
** EPITECH PROJECT, 2025
** open_window.c
** File description:
** handle window gestion
*/

/*
** EPITECH PROJECT, 2024
** my_hunter.c
** File description:
** my_hunter
*/

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "../include/my.h"
#include "../include/my_struct.h"

sfRenderWindow *create_window(void)
{
    sfRenderWindow *window = {0};
    sfVideoMode size_of_window = {0};

    size_of_window.height = 1080;
    size_of_window.width = 1920;
    size_of_window.bitsPerPixel = 64;
    window = sfRenderWindow_create(size_of_window,
        "my_radar", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 144);
    return window;
}
