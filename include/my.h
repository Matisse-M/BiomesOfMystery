/*
** EPITECH PROJECT, 2023
** my
** File description:
** CPool lib
*/

#include <stdarg.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stddef.h>
#include <stdlib.h>

#pragma once

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_isupper(char const *str);
int my_str_islower(char const *str);
int my_str_isprintable(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_show_word_array(char *const *tab);
char **my_str_to_word_array(char const *str);
char *my_strdup(char const *src);
char *concat_params(int argc, char **argv);
int my_put_unsigned(unsigned int nb);
char *convert_base(char const *nbr, char const *base_from,
    char const *base_to);
int my_intlen(int nb);
char *my_itoa(unsigned int nb);
int my_unsignedlen(unsigned int nb);
int my_float_len(double nb, int len);
int my_longlen(long nb);
int my_put_exp(double nb, int modif_long);
int my_put_exp2(double nb, int modif_long);
int my_put_float(double nb, int modif_long);
int my_put_g(double nb);
int my_put_long(long nb);
void my_unsigned_nbr(unsigned int n);
void my_positive_nbr(int nb);
int nb_length(int n);
void print(const char *format, ...);
int printf_d(const char *format, va_list param_infos, int i, int compt);
int printf_i(const char *format, va_list param_infos, int i, int compt);
int printf_s(const char *format, va_list param_infos, int i, int compt);
int printf_c(const char *format, va_list param_infos, int i, int compt);
int printf_o(const char *format, va_list param_infos, int i, int compt);
int printf_u(const char *format, va_list param_infos, int i, int compt);
int printf_x(const char *format, va_list param_infos, int i, int compt);
int printf_xm(const char *format, va_list param_infos, int i, int compt);
int printf_f(const char *format, va_list param_infos, int i, int compt);
int printf_fm(const char *format, va_list param_infos, int i, int compt);
int printf_cross(const char *format, va_list param_infos, int i, int compt);
int printf_l(const char *format, va_list param_infos, int i, int compt);
void *my_malloc(void *ptr, size_t size);
void my_memset(void *ptr, void *value, size_t num);
int strcmp_my(char const *s1, char const *s2);
char *my_strndup(char *src, int n);
char *my_realloc(char *array, int size);
int my_tablen(char **tab);
char **my_realloc2(char **array, int size);
void my_free_word_array(char **array);
void *my_calloc(size_t nb_elements, size_t size_element);
char **tok_word_array(char const *str, char *delim);
char *my_tac(char *src, char *dest);
char *my_scat(char *destination, char *source);
const char *my_scate(char *destination, const char *source);
int my_arrlen(char **arr);
