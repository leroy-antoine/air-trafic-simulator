/*
** EPITECH PROJECT, 2025
** parse_infos.c
** File description:
** parse infos inside a file
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/my_struct.h"
#include "../include/my.h"

static int fill_tower(tower_t *tower, char *buff, int ID_tower)
{
    char **arr = NULL;

    arr = my_str_to_word_array(buff, ' ');
    tower[ID_tower].position.x = (float)my_getnbr(arr[1]);
    tower[ID_tower].position.y = (float)my_getnbr(arr[2]);
    tower[ID_tower].radius = (my_getnbr(arr[3]));
    tower[ID_tower].end = 0;
    tower[ID_tower].ID = ID_tower;
    tower[ID_tower].tower_shape = set_circle_shape(tower, ID_tower);
    return 1;
}

static int fill_plane(plane_t *plane, char *buff, int ID_plane)
{
    char **arr = NULL;

    arr = my_str_to_word_array(buff, ' ');
    plane[ID_plane].position.x = (float)my_getnbr(arr[1]);
    plane[ID_plane].position.y = (float)my_getnbr(arr[2]);
    plane[ID_plane].arrival.x = (float)my_getnbr(arr[3]);
    plane[ID_plane].arrival.y = (float)my_getnbr(arr[4]);
    plane[ID_plane].speed = my_getnbr(arr[5]);
    plane[ID_plane].delay = my_getnbr(arr[6]);
    plane[ID_plane].alive = true;
    plane[ID_plane].ID = ID_plane;
    plane[ID_plane].end = 0;
    plane[ID_plane].plane_shape = set_rect_shape(plane[ID_plane].plane_shape,
        plane[ID_plane].position);
    return 1;
}

static int get_infos(char *filename, plane_t *plane, tower_t *tower)
{
    FILE *file = fopen(filename, "r");
    size_t len = 0;
    ssize_t next_line = 0;
    char *buff = NULL;
    int ID_plane = 0;
    int ID_tower = 0;

    if (file == NULL)
        return ERROR;
    next_line = getline(&buff, &len, file);
    while (next_line != -1) {
        if (buff[0] == 'A')
            ID_plane += fill_plane(plane, buff, ID_plane);
        if (buff[0] == 'T')
            ID_tower += fill_tower(tower, buff, ID_tower);
        next_line = getline(&buff, &len, file);
    }
    fclose(file);
    return SUCCESS;
}

static void *alloc_conditionnal(__attribute_maybe_unused__ tower_t *tower,
    __attribute_maybe_unused__ plane_t *plane, int nb_type, char type)
{
    if (type == 'A') {
        plane = malloc(sizeof(plane_t) * (nb_type + 1));
        if (plane == NULL)
            return NULL;
        plane[nb_type].end = END_LIST;
        return plane;
    }
    if (type == 'T') {
        tower = malloc(sizeof(tower_t) * (nb_type + 1));
        if (tower == NULL)
            return NULL;
        tower[nb_type].end = END_LIST;
        return tower;
    }
    return NULL;
}

static void *open_file(__attribute_maybe_unused__ tower_t *tower,
    __attribute_maybe_unused__ plane_t *plane, char *argv, char type)
{
    FILE *file = fopen(argv, "r");
    size_t len = 0;
    ssize_t next_line = 0;
    char *line = NULL;
    int nb_type = 0;

    if (file == NULL)
        return NULL;
    for (int i = 0; next_line != -1; i++) {
        next_line = getline(&line, &len, file);
        if (line[0] == type)
            nb_type += 1;
    }
    if (type == 'T')
        nb_type -= 1;
    fclose(file);
    return alloc_conditionnal(tower, plane, nb_type, type);
}

int parse_infos(char **argv)
{
    plane_t *plane = {0};
    tower_t *tower = {0};
    int error = SUCCESS;

    plane = open_file(tower, plane, argv[1], 'A');
    if (plane == NULL)
        return ERROR;
    tower = open_file(tower, plane, argv[1], 'T');
    if (tower == NULL) {
        free(plane);
        return ERROR;
    }
    error = get_infos(argv[1], plane, tower);
    if (error == ERROR)
        return error;
    return my_radar(plane, tower);
}
