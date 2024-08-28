#include <iostream>

char ft_upper (char str)
{
    if (97 <= str && str <= 122)
        return (str - 32);
    else
        return (str);
}

int ft_strlen (char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

int main (int argc, char **argv)
{
    int len;

    len = 0;
    if (argc > 1)
    {
        for (int i=0; i<argc; i++)
        {
            len = ft_strlen(argv[i])
            while (int j=0; j<len; j++)
                std::cout << ft_upper(argv[i][j]);
        }
        std::cout << endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}