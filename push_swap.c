#include <stdio.h>
#include <stdlib.h>

// retour en arriere
void	sa(int *tab_a, int *tablen_a);

void	sb(int *tab_b, int tablen_b);

void	ss(int *tab_a, int *tab_b, int *tablen_a, int *tablen_b);

void	pa(int **tab_a, int *tab_b, int *tablen_a, int *tablen_b);

void	pb(int *tab_a, int **tab_b, int *tablen_a, int *tablen_b);

void	ra(int *tab_a, int *tablen_a);

void	rb(int *tab_b, int *tablen_b);

void	rr(int *tab_a, int *tab_b, int *tablen_a, int *tablen_b);

void	rra(int *tab_a, int *tablen_a);

void	rrb(int *tab_b, int *tablen_b);

void	rrr(int *tab_a, int *tab_b, int *tablen_a, int *tablen_b);

int     checkdoublon(int *tab_a, int *tablen_a);

void	repartition(int *tab_a, int *tab_b, int *tablen_a, int *tablen_b);

int		checker(int *tab_a, int *tablen_a);

void	tri(int **tab_a, int **tab_b, int *tablen_a, int *tablen_b);


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

// char	*ft_strdup(char *s)
// {
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
// 	if (!str)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		str[i] = s[i];
// 		i++;
// 	}
// 	str[i] = 0;
// 	return (str);
// }

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

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	k;
	int	*tab_a;
	int	tmp;
	int	tablen_a;
	int z = 0;
	i = 1;
	j = 0;
	k = 0;
	// printf("tab au debut : %lu \n", (sizeof(tab_a) / 4));

	
	if (argc < 2)
	{
		printf("PAS ASSEZ D'ARGUMENTS !");
		return (1);
	}


	while (argv[i])
	{
		while (j < ft_strlen(argv[i]))
		{
			if(argv[i][j] == 0)
				i++;
			if((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != ' ' && argv[i][j] != '+' && argv[i][j] != '-')
				{
					printf("Error\n");
					return 1;
				}
			if (((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '-' || argv[i][j] == '+') 
			&& (argv[i][j - 1] == ' ' || j == 0))// si c'est un chiffre ou + ou - et avant c'est un ' ' ou le debut
				{
					tmp = ft_atoi(argv[i]+j);
					if(!tmp)
						{
							printf("Error\n");
							return 1;
						}
					j++;
					k++;
				}
				j++;
		}
		j = 0;
		i++;
	}
	tab_a = malloc(k * sizeof(int));
	k = 0;
	i = 0;
	j = 0;
	while (argv[i])
	{
		while (j < ft_strlen(argv[i]))
		{
			if(argv[i][j] == 0)
				i++;
			if (((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '-' || argv[i][j] == '+') 
			&& (argv[i][j - 1] == ' ' || j == 0))// si c'est un chiffre ou + ou - et avant c'est un ' ' ou le debut
				{
					tmp = ft_atoi(argv[i]+j);
					tab_a[k] = tmp;
					// printf("tmp : %d", tmp);
					j++;
					k++;
				}
				j++;
		}
		j = 0;
		i++;
	}

	
	tablen_a = k;

	if(checker(tab_a, &tablen_a) == 0)
		{
			return 1;
		}
	
	if(checkdoublon(tab_a, &tablen_a) == 1)
	{
		return 1;
	}


	int tablen_b = 0;

	int *tab_b;
	if(tablen_b>0)
		tab_b = malloc(sizeof(int) * tablen_b);
	// else
	// 	tab_b[0];

	
		// printf("k : %d", k);

	z = 0;
	printf("\n");
	printf("tab_a avant modifications : \n");
	while (z < tablen_a)
	{
		printf("%d \n", tab_a[z]);
		z++;
	}

	printf("\n");
	
	printf("tab_b avant modifications : \n");
	z = 0;
	while (z < tablen_b)
	{
		printf("%d \n", tab_b[z]);
		z++;
	}
printf("**********************************************************************\n");
// ***********************************jusque la, je n'ai fait aucune modification,
// juste checker si j'ai un doublon ou si la pile A est deja trie***********************************
	
	
	tri(&tab_a, &tab_b, &tablen_a, &tablen_b);




	printf("TEST\n");
	printf("\n");
	printf("tab_a apres tri : \n");
	while (z < tablen_a)
	{
		printf("%d \n", tab_a[z]);
		z++;
	}

	printf("\n");
	
	printf("tab_b apres tri : \n");
	z = 0;
	while (z < tablen_b)
	{
		printf("%d \n", tab_b[z]);
		z++;
	}




	if(tab_a)
		free(tab_a);
	// if(tab_b)
	// 	free(tab_b);

}



// repartition(tab_a, tab_b, &tablen_a, &tablen_b);
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("****************************max********* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");
	// printf("************************************* \n");