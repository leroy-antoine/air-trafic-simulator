/*
** EPITECH PROJECT, 2025
** event.c
** File description:
** handle event
*/

#include <SFML/Graphics.h>
#include "../include/my.h"
#include "../include/my_struct.h"

void handle_event(sfRenderWindow *window)
{
    sfEvent event;

    sfRenderWindow_pollEvent(window, &event);
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}
