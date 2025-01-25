#include <stdio.h>

// avant modif

void	sa(int *tab_a, int *tablen_a);

void	sb(int *tab_b, int *tablen_b);

void	ss(int *tab_a, int *tab_b, int *tablen_a, int *tablen_b);

void	pa(int **tab_a, int *tab_b, int *tablen_a, int *tablen_b);

void	pb(int *tab_a, int **tab_b, int *tablen_a, int *tablen_b);

void	ra(int *tab_a, int *tablen_a);

void	rb(int *tab_b, int *tablen_b);

void	rr(int *tab_a, int *tab_b, int *tablen_a, int *tablen_b);

void	rra(int *tab_a, int *tablen_a);

void	rrb(int *tab_b, int *tablen_b);

void	rrr(int *tab_a, int *tab_b, int *tablen_a, int *tablen_b);

int	checker(int *tab_a, int *tablen_a)
{
	int	i;

	i = 0;
	while (tab_a[i] < tab_a[i + 1] && i < *tablen_a)
		i++;
	// printf("checker i : %d\n", i+1);
	// printf("checker tablen_a : %d\n", tablen_a);
	if (i + 1 == *tablen_a)
	{
		printf("c'est bon\n");
		return (0);
	}
	// printf("c'est PAS bon\n");
	return (1);
}

int	checker_a_b(int *tab_a, int *tab_b, int *tablen_a, int *tablen_b)
{
	int	i;

	i = 0;
	while (tab_a[i] < tab_a[i + 1] && i < *tablen_a)
		i++;
	printf("checker_a_b i        = %d\n", i);
	printf("checker_a_b tablen_a = %d\n", *tablen_a);
}

int	checkdoublon(int *tab_a, int *tablen_a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < *tablen_a)
	{
		while (j < *tablen_a)
		{
			if (tab_a[i] == tab_a[j])
			{
				printf("doublon !!!!");
				return (1);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

void	repartition(int **tab_a, int **tab_b, int *tablen_a, int *tablen_b)
{
	int	half;
	int	i;

	half = *tablen_a / 2;
	i = 0;
	while (i < half)
	{
		pb(*tab_a, tab_b, tablen_a, tablen_b);
		i++;
	}
}

void	tri(int **tab_a, int **tab_b, int *tablen_a, int *tablen_b)
{
	int i = 0;
	int index = 0;
	int min = (*tab_a)[0];
	
    while(*tablen_a > 1)
	{
        i=0;
        index = 0;
        min = (*tab_a)[0];
		
		while (i < *tablen_a)
		{
			if ((*tab_a)[i] < min)
			{
				index = i;
				min = (*tab_a)[i];
			}
			i++;
		}
		
		// printf("val max = %d\n", max);
		// printf("index max = %d\n", index);
		i = 0;
		if (index > (*tablen_a / 2))
		{
			while (i < *tablen_a - index)
			{
				rra(*tab_a, tablen_a);
				i++;
			}
		}
		else
		{
			while (i < index)
			{
				ra(*tab_a, tablen_a);
				i++;
			}
		}
	// printf("tab_b apres test : \n");
	// int z = 0;
   	// 	printf("TEST Z %d\n", z);
   	// 	printf("TEST tablen_B %d\n", *tablen_b);

	// while (z < *tablen_b)
	// {
	// 	printf("%d \n", *tab_b[z]);
	// 	z++;
	// }
   		// printf("TEST tablen_B %d\n", *tablen_b);
   		// printf("TEST\n");

		pb(*tab_a, tab_b, tablen_a, tablen_b);
		// printf("TEST\n");

	}
	while(*tablen_b >0)
		pa(tab_a, *tab_b, tablen_a, tablen_b);
}


 //     	printf("************************************* \n");
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