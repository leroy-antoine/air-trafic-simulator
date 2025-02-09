/*
** EPITECH PROJECT, 2025
** main.C
** File description:
** main for my radar
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/my_struct.h"


int main(int argc, char **argv)
{
    int const type_of_arg = parse_argument(argv);
    int error = SUCCESS;

    if (argc != 2)
        return how_to_use();
    if (type_of_arg == H_FLAG)
        return h_flag();
    if (type_of_arg == SUCCESS)
        error = parse_infos(argv);
    if (error == ERROR)
        return how_to_use();
    else
        return SUCCESS;
}
