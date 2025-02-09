/*
** EPITECH PROJECT, 2024
** my_strncpy.c
** File description:
** read the pdf
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (n <= 0) {
        return dest;
    }
    while (i != n && src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    if (n > i || src[i] == '\0') {
        dest[i] = '\0';
    }
    return dest;
}
