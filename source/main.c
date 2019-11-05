#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>
#include <wctype.h>
#include <string.h>
#include "../ft_printf.h"

#define ah_red "\e[31m"
#define ah_end "\e[0m"

int ft_printf(char *format, ...)
{
    va_list ap;
    char **pars;
    int i;
    i = 0;

    va_start(ap, format);
    pars = tokenizer(format);
    while(pars[i])
    {
        i++;
    }
    t_token *packet = (t_token *)malloc(sizeof(t_token)* (i + 1));
    typification(pars, packet);
    order(pars, packet);
    modificators(pars, packet);
    precision(pars, packet);
    width(pars, packet);
    flags(pars, packet);
    values(i, packet, ap);
   	i = printing(packet,i);
    va_end (ap);
    return (i);
}















/*


int main()
{



	pointer_test_elseflag();

	//pointer_test_zr();
	//pointer_test_min();
	//string_test();

	//integer_test();
	//unsigned_test();
	//unsigned_test_min();

	//type_x_testelse();
	//type_x_testxzr();
	//type_x_testxmin();

    return (0);
}
*/