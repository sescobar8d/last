#include "ft_printf.h"

char    *ft_precision_str(char *string, t_flags *flags)
{
        char    *result;

        result = ft_calloc(1, (flags)->precission);
        if ((flags)->precission > ft_strlen(string))
	{
		free(result);
		return (string);
	}
	if ((flags)->has_precission == 1 &&
                (flags)->precission == 0)
                string = "";
	ft_strlcat(result,(const char *)string, (flags)->precission + 1);
	return (result);
}

void    ft_spacerc_str(void *str, int n)
{
        int             count;
        char    *s;

        s = (char *)str;
        count = 0;
        while (count < n)
        {
                s[count] = '0';
                count++;
        }
}

int             ft_sp_str(int c, t_flags **flags)
{
        if ((*flags)->zero == 1 && (*flags)->plus == 1 && (*flags)->has_width == 1
                && (*flags)->has_precission == 0)
        {
                ft_putstr_fd("+", 1);
                c = 1;
                return (c);
        }
        else
                return (c);
}

int             ft_yui_str(int c, t_flags **flags)
{
        ft_putstr_fd("-", 1);
        (*flags)->hash = 1;
        if ((*flags)->zero == 1)
                c = 1;
        return (c);
}

char    *ft_spacerz_str(char *str, int n, t_flags *flags)
{
        char    *result;
	char	*d;
        int             c;

        c = 0;
        result = ft_calloc(1, (size_t)n);
        c = ft_sp_str(c, &flags);
        if (*str == '-')
        {
                str++;
                if ((flags)->has_precission == 1 && (flags)->has_width == 1)
                {
                        ft_spacerc_str(result, ((n - c) - ft_strlen(str)));
                        d = ft_strjoin_free((ft_strjoin_free("-", result, 2)), str, 3);
                        return (d);
                }
                c = ft_yui_str(c, &flags);
        }
        if (ft_strlen(str) > (unsigned int)n)
                return (str);
        ft_spacerc_str(result, ((n - c) - ft_strlen(str)));
        d = ft_strjoin_free(result, str, 1);
        return (d);
}

