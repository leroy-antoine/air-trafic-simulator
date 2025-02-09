/*
** EPITECH PROJECT, 2025
** parse_arguent.c
** File description:
** parsing args for this pj
*/


#include <fcntl.h>
#include "../include/my.h"
#include "../include/my_struct.h"

int parse_argument(char **argv)
{
    for (int i = 1; argv[i] != NULL; i++) {
        if (my_strcmp("-h", argv[i]) == 0)
            return H_FLAG;
    }
    return SUCCESS;
}
