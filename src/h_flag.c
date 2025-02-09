/*
** EPITECH PROJECT, 2025
** h_flag.c
** File description:
** h flag for this pj
*/

#include "../include/my.h"
#include "../include/my_struct.h"

int h_flag(void)
{
    mini_printf("Air traffic simulation panel\n"
                "USAGE :\n"
                "\t./my_radar [OPTIONS] path_to_script\n"
                "\tpath_to_script"
                "\tThe path to the script file.\n"
                "OPTIONS :\n"
                "\t-h : print the usage and quit.\n");
    return SUCCESS;
}
