/*
** EPITECH PROJECT, 2025
** my_str_to_word_array.c
** File description:
** strtok homemade
*/

#include <stdlib.h>
#include "my.h"

static char *fill_array(int *new_index, const char *str,
    const char delim, int *old_index)
{
    int size_str = *new_index - *old_index;
    char *string = malloc(sizeof(char) * (size_str + 1));
    int z = 0;

    if (string == NULL)
        return NULL;
    for (int i = *old_index; i <= *new_index; i++) {
            string[z] = str[i];
            z += 1;
    }
    string[size_str] = '\0';
    *old_index = *new_index + 1;
    return string;
}

static void is_it_delim(int *i, const char *str,
    const char delim, int *nb_elem)
{
    while (str[*i] == delim && str[*i] != '\0') {
        *i += 1;
        if (str[*i] == '\0')
            *nb_elem -= 1;
    }
}

static int count_elem(const char *str, const char delim)
{
    int nb_elem = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delim) {
            is_it_delim(&i, str, delim, &nb_elem);
            nb_elem += 1;
        }
        if (str[i + 1] == '\0')
            nb_elem += 1;
    }
    return nb_elem;
}

static int check_is_delim(const char *str, const char delim, int new_index)
{
    for (int i = new_index; str[i] == delim; i++) {
        if (str[i] != delim) {
            return new_index;
        }
        if (str[i] == delim) {
            new_index += 1;
        }
        if (str[i] == '\0') {
            return new_index;
        }
    }
    return new_index;
}

static int calculate_index(const char *str, const char delim, int new_index)
{
    int i = new_index + 1;

    for (; str[i] != delim && str[i] != '\0'; i++) {
    }
    return i;
}

char **my_str_to_word_array(const char *str, const char delim)
{
    int nb_elem = count_elem(str, delim);
    char **array = malloc(sizeof(char *) * (nb_elem + 1));
    int index = 0;
    int old_index = 0;
    int new_index = 0;
    int test = 0;

    if (array == NULL)
        return NULL;
    array[nb_elem] = NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (index == nb_elem)
            break;
        if (str[i] == delim || str[i + 1] == '\0') {
            new_index = calculate_index(str, delim, new_index);
            array[index] = fill_array(&new_index, str, delim, &old_index);
            index += 1;
        }
    }
    return array;
}
