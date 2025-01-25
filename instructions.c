// ecrire les instructions
#include <stdio.h>
#include <stdlib.h>



void	sa(int *tab_a, int *tablen_a)
{
	int	i;
	int	tmp;

	i = 0;
	if (*tablen_a < 2)
	{
		printf("il n y a que %d arguments, il en faut au moins 2 !!!\n",
			*tablen_a);
	}
	
	else
	{
		tmp = tab_a[0];
		tab_a[0] = tab_a[1];
		tab_a[1] = tmp;
	}

	printf("sa\n");
	// tab_a[tablen] = 999;
	// return (tab);
}

void	sb(int *tab_b, int *tablen_b)
{
	int	i;
	int	tmp;

	i = 0;
	if (*tablen_b < 2)
	{
		printf("il n y a que %d arguments, il en faut au moins 2 !!!\n",
			*tablen_b);
	}
	
	else
	{
		tmp = tab_b[0];
		tab_b[0] = tab_b[1];
		tab_b[1] = tmp;
	}

	printf("sb\n");
	// tab_a[tablen] = 999;
	// return (tab);
}


void	ss(int *tab_a, int *tab_b, int *tablen_a, int *tablen_b)
{
	int	i;
	int	tmp;

	i = 0;
	if (*tablen_a < 2)
	{
		printf("il n y a que %d arguments, il en faut au moins 2 !!!\n",
			*tablen_a);
	}
	else if (*tablen_b < 2)
	{
		printf("il n y a que %d arguments, il en faut au moins 2 !!!\n",
			*tablen_b);
	}
	
	else
	{
		tmp = tab_a[0];
		tab_a[0] = tab_a[1];
		tab_a[1] = tmp;

		tmp = tab_b[0];
		tab_b[0] = tab_b[1];
		tab_b[1] = tmp;

	}

	printf("ss\n");

	// i = 0;
	// if (tablen_b < 2)
	// {
	// 	printf("il n y a que %d arguments, il en faut au moins 2 !!!\n",
	// 		tablen_b);
	// }
	
	// else
	// {
	// 	tmp = tab_b[0];
	// 	tab_b[0] = tab_b[1];
	// 	tab_b[1] = tmp;
	// }
	// tab_a[tablen] = 999;
	// return (tab);
}


void	pa(int **tab_a, int *tab_b, int *tablen_a, int *tablen_b)
{
	if(*tablen_b == 0)
		return;

	int taille = *tablen_a;

	int i = 0;
	*tablen_a = taille + 1;
	int *tab_tmp = (int *)malloc(sizeof(int) * taille);

	while (i < taille)
	{
		tab_tmp[i] = (*tab_a)[i];
		i++;
	}

	// free(tab_a);
	*tab_a = (int *)malloc(sizeof(int) * (*tablen_a));
	
	(*tab_a)[0] = tab_b[0];
	
	i = 0;


	while (i < taille)
	{
		(*tab_a)[i+1] = tab_tmp[i];
		i++;
	}

	// free(tab_tmp);
	i = 0;
	while (i< *tablen_b-1)
	{
		tab_b[i] = tab_b[i+1];
		i++;
	}
	// printf("tablen_b : %d \n", *tablen_b);
	*tablen_b = *tablen_b - 1;
	// printf("tablen_b : %d \n", *tablen_b);
	free(tab_tmp);

	printf("pa\n");

}

void	pb(int *tab_a, int **tab_b, int *tablen_a, int *tablen_b)
{
	if(*tablen_a == 0)
		return;

	int taille = *tablen_b;

	int i = 0;
	*tablen_b = taille +1;
	int *tab_tmp = (int *)malloc(sizeof(int) * taille);

	while(i < taille)
	{
		tab_tmp[i] = (*tab_b)[i];
		i++;
	}
	// printf("TEST\n");
	// if(*tab_b)
		// free(*tab_b);
	// printf("TEST\n");
	*tab_b = (int *)malloc(sizeof(int) * (*tablen_b));
	(*tab_b)[0] = tab_a[0];

	// if(taille >0)
	// 	free(tab_b);
	

	i = 0;
	

	while(i < taille)
	{
		(*tab_b)[i+1] = tab_tmp[i];
		i++;
	}

	i = 0;
	while (i< *tablen_a-1)
	{
		tab_a[i] = tab_a[i+1];
		i++;
	}
	*tablen_a = *tablen_a - 1;

	free(tab_tmp);

	printf("pb\n");

}



void	ra(int *tab_a, int *tablen_a)
{
	int i = 0;
	int tmp = tab_a[0];
	while(i<*tablen_a)
	{
		tab_a[i] = tab_a[i + 1];
		i++;
	}

	tab_a[*tablen_a-1] = tmp;

	printf("ra\n");
}

void	rb(int *tab_b, int *tablen_b)
{
	int i = 0;
	int tmp = tab_b[0];
	while(i<*tablen_b)
	{
		tab_b[i] = tab_b[i + 1];
		i++;
	}

	tab_b[*tablen_b-1] = tmp;

	printf("rb\n");
}

void	rr(int *tab_a, int *tab_b, int *tablen_a, int *tablen_b)
{
	int i = 0;
	int tmp = tab_a[0];
	while(i<*tablen_a)
	{
		tab_a[i] = tab_a[i + 1];
		i++;
	}

	tab_a[*tablen_a-1] = tmp;

	tmp = tab_b[0];
	i = 0;

	while(i<*tablen_b)
	{
		tab_b[i] = tab_b[i + 1];
		i++;
	}

	tab_b[*tablen_b-1] = tmp;

	printf("rr\n");
}


void	rra(int *tab_a, int *tablen_a)
{
	int i = 0;
	int tmp = tab_a[*tablen_a - 1];
	while(i < *tablen_a)
	{
		tab_a[*tablen_a-i] = tab_a[*tablen_a-i-1];
		i++;
	}
	tab_a[0] = tmp;

	printf("rra\n");
}

void	rrb(int *tab_b, int *tablen_b)
{
	int i = 0;
	int tmp = tab_b[*tablen_b - 1];
	while(i < *tablen_b)
	{
		tab_b[*tablen_b-i] = tab_b[*tablen_b-i-1];
		i++;
	}
	tab_b[0] = tmp;

	printf("rrb\n");
}


void	rrr(int *tab_a, int *tab_b, int *tablen_a, int *tablen_b)
{
	int i = 0;
	int tmp = tab_a[*tablen_a - 1];
	while(i < *tablen_a)
	{
		tab_a[*tablen_a-i-1] = tab_a[*tablen_a-i-2];
		// printf("verif index %d\n", tablen_a-i);
		i++;
	}
	tab_a[0] = tmp;

	i = 0;
	tmp = tab_b[*tablen_b - 1];
	while(i < *tablen_b)
	{
		// printf("i : %d\n", i);
		tab_b[*tablen_b-i-1] = tab_b[*tablen_b-i-2];
		i++;
	}
	tab_b[0] = tmp;

	printf("rrr\n");
}



