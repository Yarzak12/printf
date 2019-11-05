#include "libft.h"
#include <stdio.h>
# define MAX 1000000000000000000
//18
# define NORM 100000
//6



static void normstr(char *str, int len)
{
	int i;
	int f;

	i = len -1;
	f = 0;
	while(i > 0)
	{
		if(str[i] > 57)
		{
			str[i-1] = str[i - 1] + (str[i] - 48) / 10;
			str[i] = (str[i] -48)%10 + 48;
			f = 1;
		}
		i--;
		if (i == 0 && f == 1)
		{
			i = len -1;
			f = 0;
		}
	}
}

static char *mulstr(char *str , int m)
 {
	int len = ft_strlen(str);
	int i = 0;

	while (i < len)
	{
		if(str[i]!=0)
		{
			str[i] = (str[i] - 48) * m + 48;
		}
		i++;
	}
	normstr(str, len);
	return (str);
 }

void normalize(unsigned long *m, int size)
{
	int i;

	i = 0;
	while (i < size -1)
	{
		if (m[i] >= MAX)
		{
			m[i+1] = m[i] / MAX;
			m[i] = m[i] % MAX;
		}
		i++;
	}
}

unsigned long *mass_mult(unsigned long *m, int size, int mult)
{
	int i;

	i = 0;
	while(i < size)
	{
		m[i] = m[i] * mult;
		i++;
	}
	normalize(m,size);
	return (m);
}


void	mass_sum(unsigned long *g, unsigned long *d, int size)
{
	int i;

	i = 0;
	while(i < size)
	{
		g[i] = g[i]  + d[i];
		i++;
	}
	normalize(g,size);
}

void	mass_div(unsigned long *m, int size, int div)
{
	int i;

	i = 1;
	m[0] = m[0] / div;
	while(i < size)
	{
		m[i -  1] += MAX * (m[i] % div);
		m[i] = m[i] / div;
		i++;
	}
	normalize(m,size);
}




char * ft_doubletostr(long double d, int p)
{
	t_cast cs;
	cs.dl = d;

	t_cast sys;
	long double test = 1.525;

	sys.dl = test;
	int e =sys.exp - 16383;
	unsigned long u = sys.mant ;


	printf("sign: %d\n", sys.sign);
	printf("exp: %d\n", sys.exp - 16383);
	printf("mant: %lu\n", sys.mant );


//	char * s_int = ft_strnew(303);
//	ft_memset(s_int,'0',303);

	char *mantisse;

	mantisse = ft_strnew(64 );
	for (int  i = 0 ; i < 64; i++)
	{
		mantisse[63 - i] = 48 + (int)(u % 2);
		u = u / 2;
	}

	unsigned long i_m[5];
	unsigned long s_m[5];

	int i = 0;

	while(i < 5) {

		s_m[i] = 0;
		i_m[i] = 0;
		i++;
	}
	//i_m[0] = 5 * NORM;

	i_m[4] = 1;


	i = 0;


	while (i < 20)
	{

		//mass_mult(i_m,5,10);

		mass_div(i_m,5,2);

		i++;
	}



	i = 0;

	while (i < 5)
	{
		printf("%lu\n", i_m[i]);
		i++;
	}




	
	printf("%s\n",mantisse);




	return 0;
}



