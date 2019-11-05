//
// Created by Sparr Lenore on 04/10/2019.
//

#ifndef FT_PRINTF_FT_PRINTF_H
#define FT_PRINTF_FT_PRINTF_H

# include <wchar.h>
#include <stdio.h>
#include "libft/libft.h"
#include <stdlib.h>
#include <stdarg.h>
#include <wctype.h>




typedef struct  s_token
{
    int     f_min;
    int     f_pls;
    int     f_spc;
    int     f_oct;
    int     f_zr;

    int     width; // int *
    int     presicion; // int *
    char    *modificator; // h hh l ll L z


    char    type; // diouxX fF eE gG cS
    int     order; // $
    void    *value; // variable
    long double     swim;
    long long int    disc;
    long long  unsigned int  udisc;

    int sign;




}                t_token ;


void integer_test(void);
void string_test(void);
void unsigned_test(void);
void unsigned_test_min(void);

void type_x_testelse(void);
void type_x_testxzr(void);
void type_x_testxmin(void);


void pointer_test_elseflag(void);
void pointer_test_zr(void);
void pointer_test_min(void);


int  printing(t_token *packet, int size);
void  values(int size,t_token *packet,va_list ap);
char **tokenizer(char *format);


void typification(char **pars, t_token *packet);
void order(char **pars, t_token *packet);
void precision(char **pars, t_token *packet);
void width(char **pars, t_token *packet);
void flags(char **pars, t_token *packet);
void modificators(char **pars, t_token *packet);

char *srmax(t_token *t, int len);
int k_factor(t_token *t);



int nesting_char(t_token *token);
int nesting_str(t_token *t);
int nesting_di(t_token *t);
int nesting_u(t_token *t);
int nesting_x(t_token *t);
int nesting_pointer(t_token *t);

int ft_printf(char *format, ...);


#endif //FT_PRINTF_FT_PRINTF_H
