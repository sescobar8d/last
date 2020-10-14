#include "ft_printf.h"

void    ft_r1_str(char *spaces)
{
        ft_putstr_fd("+", 1);
        spaces[ft_strlen(spaces) - 1] = '\0';
}

int             ft_r2_str(char *spaces, t_flags **flags)
{
        if ((*flags)->has_precission == 1 &&
                (*flags)->precission == 0)
        {
                ft_spacer(spaces, (*flags)->width);
                return (1);
        }
        else
                return (0);
}

char    *lep_str(t_flags **flags, char *spaces, char *string)
{
	char	*j;

	j = NULL;
        ft_spacer(spaces, (*flags)->space);
        if ((*flags)->plus == 1 && (*flags)->has_precission == 1
                && (*flags)->has_width == 1 && (ft_atoi(string) >= 0))
        {
                if ((*flags)->minus == 0)
                        spaces[ft_strlen(spaces) - 1] = '+';
                else
                        ft_r1_str(spaces);
        }
	//spaces = ft_strjoin_free(spaces, j, 3);
        return (spaces);
}

char    *ft_spaces_str(char *string, t_flags *flags)
{
        char    *spaces;
	char	*l;

	l = NULL;
        (flags)->space = ((flags)->width - ft_strlen(string));
        spaces = ft_calloc(1, (size_t)(flags)->width);
        if (ft_r2_str(spaces, &flags) == 1)
	{
		spaces = ft_strjoin_free(spaces, l, 3);
		return (spaces);
	}
        spaces = lep_str(&flags, spaces, string);
        if ((flags)->minus == 1)
        {
                spaces = ft_strjoin_free(string, spaces, 2);
                return (spaces);
        }
        if ((flags)->space < 0)
        {
                free(spaces);
                return (string);
        }
        spaces = ft_strjoin_free(spaces, string, 1);
        return (spaces);
}
