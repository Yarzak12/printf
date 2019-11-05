typedef union s_cast
{
    struct
    {
        unsigned long int mant :64 ;
        unsigned long int exp  :15;
        int sign :1;
    };

    long double n;


} t_cast;




int main()
{








	return 0;
}



