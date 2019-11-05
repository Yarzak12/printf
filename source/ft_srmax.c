#include "../ft_printf.h"

char * srmax(t_token *t, int len)
{

    char *tmp = NULL;

    int sign = 1;


    if (t->sign >= 0 && (t->f_pls  || t->f_spc))
        len++;
    len = len + t->f_oct;

    if (t->width >= len)
    {
        if (t->width > t->presicion)
            tmp = ft_strnew(t->width);
        else if(t->width <= t->presicion)
        {
            if (sign < 0 || t->f_pls|| t->f_spc)
            {
                tmp = ft_strnew(t->presicion  + 1);
                t->width= t->presicion + 1;
            }
            else
            {
                tmp = ft_strnew(t->presicion);
                t->width= t->presicion;
            }
        }
    }
    else
    {
        tmp = ft_strnew(len + 2);
    }
    return (tmp);
}

int k_factor(t_token *t)
{
    int k;
    k =0;
    if (t->sign >= 0 && (t->f_pls || t->f_spc))
        k = 1;
    if (t->sign < 0)
        k = 1;
    return k;
}



