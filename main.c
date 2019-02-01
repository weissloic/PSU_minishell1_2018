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
    path->stock_my_path = malloc(sizeof(char*) * 100);
    path->indice_path = malloc(sizeof(char*) * 100);
    path->cat_my_path = malloc(sizeof(char*) * 100);
    path->path_withoutspace = malloc(sizeof(char*) * 100);
    path->stock_my_log = malloc(sizeof(char*) * 100);
    

    for (int malloc_stock = 0; malloc_stock < 100; malloc_stock++)
        path->path_withoutspace[malloc_stock] = malloc(sizeof(char*) * 100);

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
        if (new_envp[i][0] == 'P' && new_envp[i][1] == 'A' && new_envp[i][2] == 'T' && new_envp[i][3] == 'H')
            e = i;
    }
    return (e);
}

int get_log(int ac, char **av, char **new_envp)
{
    int e = 0;
    int i = 0;
    for (i; i < 50; i++) {
        if (new_envp[i][0] == 'H' && new_envp[i][1] == 'O' && new_envp[i][2] == 'M' && new_envp[i][3] == 'E')
            e = i;
    }
    return (e);
}

void array_path(path_t *path, int ac, char **av)
{
    char adding[] = "/";

    for (int pol = 0; pol < 9; pol++)
        strcpy(path->indice_path[pol], path->stock_my_path[pol]);

    for (int mol = 0; mol < 9; mol++)
        strcat(path->indice_path[mol], adding);

    for (int cpy = 0; cpy < 9; cpy++)
        strcpy(path->cat_my_path[cpy], path->indice_path[cpy]);
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
    path->stock_my_option = malloc(sizeof(char*) * 100);
    for (int j = 0; j < 100; j++)
        path->stock_my_option[j] = malloc(sizeof(char) * 100);
    int cols_arg = 0;
    int lines_arg = 0;
            for (int i = 0; i != strlen(path->buffer) - 1; i++) {
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

int main (int ac, char **av, char **new_envp)
{
    path_t *path = malloc(sizeof(path_t));

    int e = 0;

    if (new_envp == NULL)
        return (84);

    int counter = 0;
    int line = 0;
    char *copy_arg = malloc(sizeof(char) * 100);
    char *current_path;
    char folder[200];
    char *new_argv[] = { "ls", NULL};
    char *zizi[] = { NULL };
    int log_name;
    int fill_name = 0;


    malloc_array(path);
    e = get_path(ac, av, new_envp);
    
    for (int a = 5; a != strlen(new_envp[e]); a++) {
        if (new_envp[e][a] == ':') {
            counter = 0;
            line++;
        } else {
            path->stock_my_path[line][counter] = new_envp[e][a];
            counter++;
        }
    }
    log_name = get_log(ac, av, new_envp);
    for (int i = 5; i != strlen(new_envp[log_name]); i++) {
        path->stock_my_log[0][fill_name] = new_envp[log_name][i];
        fill_name++;
    }
    array_path(path, ac, av);
    while (1) {
        printf("$>");
        if (getline(&path->buffer, &path->len, stdin) == -1) {
            my_printf("Error");
            return (84);
        } else {
            if (my_strncmp(path->buffer, "pwd", 3) == 0) {
                current_path = getcwd(folder, 200);
                printf("%s\n", current_path); 
            }
            if (my_strncmp(path->buffer, "env", 3) == 0) {
                for (int u = 0; new_envp[u] != '\0'; u++)
                    printf("%s\n", new_envp[u]);
            }
            if (my_strncmp(path->buffer, "exit", 4) == 0)
                exit (0);
            if (my_strncmp(path->buffer, "cd", 2) == 0) {
                get_file(path);
                int lenght = strlen(path->file);
                if (lenght == 0)
                    chdir(path->stock_my_log[0]);
                else
                    chdir(path->file);
            }

            strcpy(copy_arg, path->buffer);

            for (int alexis = 0; alexis < 9; alexis++)
                strncat(path->cat_my_path[alexis], path->buffer, my_strspace(path->buffer));
        }
        space_count(path);

            int f = fork();
            int status = 0;

            if (f < 0)
                exit (84);
            if (f == 0) {
                for (int i = 0; i < 3; i++)
                    execve(path->cat_my_path[i], path->stock_my_option, new_envp);
                    //if (execve(path->cat_my_path[i], path->stock_my_option, new_envp) == -1)
                        //perror("execve failed");
            }
            else if (f > 0) {
                if (wait(&status) < 0)
                    return (84);
            }
        array_path(path, ac, av);
        for (int print = 0; print != 7; print++)
            printf("%s", path->path_withoutspace[print]);
        printf("\n");
    }
}

void get_file(path_t *path)
{
    int e = 0;
    int counter_space = 0;
    path->file = malloc(sizeof(char) * 100);
    char *command = malloc(sizeof(char) * 100);
    int lenght = strlen(path->buffer) - 1;

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