/*
** EPITECH PROJECT, 2018
** 103cypher
** File description:
** description
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <dirent.h>
#include <pwd.h>
#include <string.h>
#include <grp.h>
#include <errno.h>

typedef struct path_t {
    char **stock_my_path;
    char **indice_path;
    char **cat_my_path;
    char **path_withoutspace;
    char **stock_my_log;
    char **stock_my_option;
    char *buffer;
    char *file;
    size_t len;
    int e;
} path_t;

int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_printf(char *s, ...);
void my_isflagfunction(int i, char *s, va_list ap);
void my_iswritefunction(int i, int u,  char *s, va_list ap);
void my_getocta(char *s);
void my_puthexa(int);
void my_puthexaupp(int);
void my_putbinary(int);
void my_putocta(int);
void my_putadress_pointer(int);
void my_putpercentage(char);
void my_put_nbr2(unsigned int nb);
void my_putstroctal(char *);
void my_putcharacter1(va_list ap);
void my_putstring1(va_list ap);
void my_putnumber1(va_list ap);
void my_puthexa1(va_list ap);
void my_puthexaupp1(va_list ap);
void my_putocta1(va_list ap);
void my_putbinary1(va_list ap);
void my_putadress_pointer1(va_list ap);
void my_putpercentage1(va_list ap);
void my_u_put_nbr1(va_list ap);
void func_put_stroctal1(va_list ap);
char    *my_strcat(char *dest, char *src);

static void (*point_func[12])(va_list ap) = {
    &my_putcharacter1,
    &my_putstring1,
    &my_putnumber1,
    &my_puthexa1,
    &my_puthexaupp1,
    &my_putocta1,
    &my_putbinary1,
    &my_putadress_pointer1,
    &my_putpercentage1,
    &my_u_put_nbr1,
    &func_put_stroctal1,
    &my_putnumber1
};
