#include <stdio.h>
#include <stdlib.h>

static int	countwords(char const *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	if (!s[0])
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			j++;
		i++;
	}
	if (s[i] == 0 && s[i - 1] != c)
		j++;
	return (j);
}

static int	len(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*mallocaword(char const *str, int start, int end)
{
	int		i;
	char	*s;

	i = 0;
	s = malloc(sizeof(char) * (end - start + 1));
	if (s == NULL || !str[0])
		return (NULL);
	while (start < end)
	{
		s[i] = str[start];
		start++;
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	int		index;
	char	**tab;

	index = -1;
	i = 0;
	k = 0;
	tab = malloc(sizeof(char *) * (countwords(s, c) + 1));
	if (!s || !tab)
		return (NULL);
	while (i <= len(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == len(s)) && index >= 0)
		{
			tab[k] = mallocaword(s, index, i);
			k++;
			index = -1;
		}
		i++;
	}
	tab[k] = NULL;
	return (tab);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	s;
	int	nbr;

	s = 1;
	nbr = 0;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + (nptr[i] - 48);
		i++;
	}
	return (nbr * s);
}

typedef struct s_list
{
	int				*value;
	struct s_list	*next;
}					t_list;

void	push_swp(t_list *pile_a)
{
}

int	main(int argc, char *argv[])
{
	int i = 1;
	int j = 0;
	int k = 0;
	// int *tableau = malloc(50 * sizeof(int));
	int total = 0;
	char *str = malloc(100 * sizeof(char));
	t_list *tableau = malloc(50 * sizeof(t_list));

	if (argc < 2)
	{
		printf("PAS ASSEZ D'ARGUMENTS\n");
		return (0);
	}
	while (argv[i])
	{
		str[k] = ' ';
		k++;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != ' ')
			{
				printf("ARGUMENT INCORRECT");
				return (0);
			}
			str[k] = argv[i][j];
			k++;
			j++;
		}
		i++;
		j = 0;
	}
	// printf("ON EST SORTI DE LA BOUCLE\n");

	char **wordtab = ft_split(str, ' ');
	i = 0;
	while (wordtab[i])
	{
		tableau[i].value = ft_atoi(wordtab[i]);
		// printf("%d\n", tableau[i].value);

		tableau[i].next = NULL;
		i++;

	}
	i = 0;
	while (tableau[i].next)
	{
		printf("%d\n", tableau[i].value);
		i++;
	}

	// str[k] = 0;
	// char **tab = ft_split("str", ' ');
	// while (tab[i])
	// {
	// 	tableau[i] = ft_atoi(tab[i]);
	// 	printf("%s\n", tab[i]);
	// 	i++;
	// }
	// // tableau[i] = NUL;
	// i = 0;
	// while (tableau[i])
	// {
	// 	printf("%d\n", tableau[i]);
	// 	i++;
	// }

	// push_swp()
}