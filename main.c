/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include "include/my.h"

int my_strspace (char *str)
{
    int i = 0;
    for (i; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            return (i);
    }
    return (i - 1);
}

void space_count(path_t *path)
{
    path->stock_my_option = malloc(sizeof(char *) * 100);
    for (int j = 0; j < 100; j++)
        path->stock_my_option[j] = malloc(sizeof(char) * 100);
    int cols_arg = 0;
    int lines_arg = 0;
    for (int i = 0; i != my_strlen(path->buffer) - 1; i++) {
        if (path->buffer[i] == ' ') {
            lines_arg++;
            cols_arg = 0;
        }
        else {
            path->stock_my_option[lines_arg][cols_arg] = path->buffer[i];
            cols_arg++;
        }
    }
    lines_arg += 1;
    path->stock_my_option[lines_arg] = NULL;
}

void detect_function(path_t *path, char **new_envp)
{
    char *current_path;
    char folder[200];
    int lenght = 0;
    if (my_strncmp(path->buffer, "pwd", 3) == 0) {
        current_path = getcwd(folder, 200);
        my_printf("%s\n", current_path);
    }
    if (my_strncmp(path->buffer, "env", 3) == 0) {
        for (int u = 0; new_envp[u] != '\0'; u++)
            my_printf("%s\n", new_envp[u]);
    }
    if (my_strncmp(path->buffer, "exit", 4) == 0) exit (0);
    if (my_strncmp(path->buffer, "cd", 2) == 0) {
        get_file(path);
        lenght = my_strlen(path->file);
        if (lenght == 0)
            chdir(path->stock_my_log[0]);
        else
            chdir(path->file);
    }
}

char *my_strncat(char *dest, char *src, int nb)
{
    int len;
    int i;

    len = my_strlen(dest);
    i = 0;
    while (i < nb && src[i])
    {
        dest[len + i] = src[i];
        i = i + 1;
    }
    dest[len + i] = '\0';
    return (dest);
}

char *my_strcpy(char *dest, char *src)
{
    char * tmp = dest;
    while (*dest = *src){
        dest++;
        src++;
    }
    return tmp;
}