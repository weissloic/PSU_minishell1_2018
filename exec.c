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

int main (int ac, char **av, char **new_envp)
{
    if (new_envp == NULL)
        return (84);
    if (new_envp[0] == 0)
        return (84);
    path_t *path = malloc(sizeof(path_t));
    path->e = 0;
    char *new_argv[] = { "ls", NULL};
    char *zizi[] = { NULL };
    path->len = 0;
    path->buffer = NULL;
    malloc_array(path);
    path->e = get_path(ac, av, new_envp);
    fill_array(new_envp, path, ac, av);
    array_path(path, ac, av);
    while (1)
        print_function(path, ac, av, new_envp);
}

void fill_array(char **new_envp, path_t *path, int ac, char **av)
{
    int line = 0;
    int counter = 0;
    int log_name;
    int fill_name = 0;

    for (int a = 5; a != my_strlen(new_envp[path->e]); a++) {
        if (new_envp[path->e][a] == ':') {
            counter = 0;
            line++;
        } else {
            path->stock_my_path[line][counter] = new_envp[path->e][a];
            counter++;
        }
    }
    log_name = get_log(ac, av, new_envp);
    for (int i = 5; i != my_strlen(new_envp[log_name]); i++) {
        path->stock_my_log[0][fill_name] = new_envp[log_name][i];
        fill_name++;
    }
}

void print_function(path_t *path, int ac, char **av, char **new_envp)
{
    char *copy_arg = malloc(sizeof(char) * 100);
    my_printf("$>");
    if (getline(&(path->buffer), &(path->len), stdin) == -1) {
        return (84);
    }
    else {
        detect_function(path, new_envp);
        my_strcpy(copy_arg, path->buffer);
        for (int alexis = 0; alexis < 9; alexis++)
            my_strncat(path->cat_my_path[alexis],
            path->buffer, my_strspace(path->buffer));
    }
    space_count(path);
    if (my_strncmp(path->buffer, "pwd", 3) != 0 &&
    my_strncmp(path->buffer, "env", 3) != 0) {
        execcmd(path, new_envp);
    }
    array_path(path, ac, av);
    for (int print = 0; print != 7; print++)
        my_printf("%s", path->path_withoutspace[print]);
}

void execcmd(path_t *path, char **new_envp)
{
    int f = fork();
    int status = 0;

    if (f < 0)
        exit (84);
    if (f == 0) {
        for (int i = 0; i < 3; i++)
            execve(path->cat_my_path[i], path->stock_my_option, new_envp);
        }
    else if (f > 0) {
        if (wait(&status) < 0)
            return (84);
    }
}

void get_file(path_t *path)
{
    int e = 0;
    int counter_space = 0;
    path->file = malloc(sizeof(char) * 100);
    char *command = malloc(sizeof(char) * 100);
    int lenght = my_strlen(path->buffer) - 1;
    for (int i = 0; i != lenght; i++) {
        if (counter_space == 0) {
            if (path->buffer[i] == ' '){
                counter_space++;
                e = 0;
            }
            else {
                command[e] = path->buffer[i];
                e++;
            }
        } else if (counter_space > 0) {
            if (path->buffer[i] != ' ' && path->buffer[i] != '\t') {
                path->file[e] = path->buffer[i];
                e++;
            }
        }
    }
}