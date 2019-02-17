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

void malloc_array(path_t *path)
{
    path->stock_my_path = malloc(sizeof(char *) * 100);
    path->indice_path = malloc(sizeof(char *) * 100);
    path->cat_my_path = malloc(sizeof(char *) * 100);
    path->path_withoutspace = malloc(sizeof(char *) * 100);
    path->stock_my_log = malloc(sizeof(char *) * 100);
    for (int malloc_stock = 0; malloc_stock < 100; malloc_stock++)
        path->path_withoutspace[malloc_stock] = malloc(sizeof(char *) * 100);

    for (int i = 0; i < 100; i++)
        path->stock_my_path[i] = malloc(sizeof(char) * 100);

    for (int ru = 0; ru < 100; ru++)
        path->indice_path[ru] = malloc(sizeof(char) * 100);

    for (int test = 0; test < 100; test++)
        path->cat_my_path[test] = malloc(sizeof(char) * 100);

    for (int lolo = 0; lolo < 100; lolo++)
        path->stock_my_log[lolo] = malloc(sizeof(char) * 100);
}

int get_path(int ac, char **av, char **new_envp)
{
    int e = 0;
    int i = 0;
    for (i; i < 20; i++) {
        if (new_envp[i][0] == 'P' && new_envp[i][1] == 'A'
        && new_envp[i][2] == 'T' && new_envp[i][3] == 'H')
            e = i;
    }
    return (e);
}

int get_log(int ac, char **av, char **new_envp)
{
    int e = 0;
    int i = 0;
    for (i; i < 50; i++) {
        if (new_envp[i][0] == 'H' && new_envp[i][1] == 'O' &&
        new_envp[i][2] == 'M' && new_envp[i][3] == 'E')
            e = i;
    }
    return (e);
}

void array_path(path_t *path, int ac, char **av)
{
    char adding[] = "/";

    for (int pol = 0; pol < 9; pol++)
        my_strcpy(path->indice_path[pol], path->stock_my_path[pol]);

    for (int mol = 0; mol < 9; mol++)
        my_strcat(path->indice_path[mol], adding);

    for (int cpy = 0; cpy < 9; cpy++)
        my_strcpy(path->cat_my_path[cpy], path->indice_path[cpy]);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; i < n && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++);
    if (i == n || (s1[i] == '\0' && s2[i] == '\0'))
        return (0);
    else if (s1[i] > s2[i])
        return (1);
    else
        return (-1);
}