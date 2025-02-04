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
	return 9999;
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

void tri_three(int **tab_a, int *tablen_a)
{
	int max = (*tab_a)[0];
	int min = (*tab_a)[0];
	int i = 0;
	while(i < *tablen_a)
	{
		if((*tab_a)[i] < min)
			min = (*tab_a)[i];
		if((*tab_a)[i] > max)
			max = (*tab_a)[i];
		i++;
	}

	while(checker(*tab_a, tablen_a) != 0)
	{
		if((*tab_a)[2] == max)
			sa(*tab_a, tablen_a);
		else if((*tab_a)[0] == min || (*tab_a)[1] == max)
			rra(*tab_a, tablen_a);
		else if((*tab_a)[0] == max)
			ra(*tab_a, tablen_a);
	}
}

void tri_four(int **tab_a, int **tab_b, int *tablen_a, int *tablen_b)
{
	int max = (*tab_a)[0];
	int min = (*tab_a)[0];
	int i = 0;
	while(i < *tablen_a)
	{
		if((*tab_a)[i] < min)
			min = (*tab_a)[i];
		if((*tab_a)[i] > max)
			max = (*tab_a)[i];
		i++;
	}

	if((*tab_a)[1] == min)
		ra(*tab_a, tablen_a);
	if((*tab_a)[2] == min)
	{
		ra(*tab_a, tablen_a);
		ra(*tab_a, tablen_a);

	}
	if((*tab_a)[3] == min)
		rra(*tab_a, tablen_a);


	pb(*tab_a, tab_b, tablen_a, tablen_b);
	tri_three(tab_a, tablen_a);
	pa(tab_a, *tab_b, tablen_a, tablen_b);


/* 	if((*tab_a)[0] > (*tab_a)[1] && (*tab_a)[0] < (*tab_a)[2] && (*tab_a)[0] < (*tab_a)[3])
	{
		sa(*tab_a, tablen_a);
	}
	if((*tab_a)[0] > (*tab_a)[1] && (*tab_a)[0] > (*tab_a)[2] && (*tab_a)[0] < (*tab_a)[3])
	{
		rra(*tab_a, tablen_a);
		sa(*tab_a, tablen_a);
		ra(*tab_a, tablen_a);
		ra(*tab_a, tablen_a);
	}
	if((*tab_a)[0] == max)
		ra(*tab_a, tablen_a); */
	
}

void tri_five(int **tab_a, int **tab_b, int *tablen_a, int *tablen_b)
{
}


// void	tri(int **tab_a, int **tab_b, int *tablen_a, int *tablen_b)
// {
// 	int i = 0;
// 	int index = 0;
// 	int min = (*tab_a)[0];
	
//     while(*tablen_a > 1)
// 	{
//         i=0;
//         index = 0;
//         min = (*tab_a)[0];
		
// 		while (i < *tablen_a)
// 		{
// 			if ((*tab_a)[i] < min)
// 			{
// 				index = i;
// 				min = (*tab_a)[i];
// 			}
// 			i++;
// 		}
		
// 		i = 0;
// 		if (index > (*tablen_a / 2))
// 		{
// 			while (i < *tablen_a - index)
// 			{
// 				rra(*tab_a, tablen_a);
// 				i++;
// 			}
// 		}
// 		else
// 		{
// 			while (i < index)
// 			{
// 				ra(*tab_a, tablen_a);
// 				i++;
// 			}
// 		}


// 		pb(*tab_a, tab_b, tablen_a, tablen_b);

// 	}
// 	while(*tablen_b >0)
// 		pa(tab_a, *tab_b, tablen_a, tablen_b);
// }

/* void	tri(int **tab_a, int **tab_b, int *tablen_a, int *tablen_b)
{

	int i = 0;
	int index_min = 0;
	int index_max = 0;
	int compteur = 0;

	int min = (*tab_a)[0];
	int max = (*tab_a)[0];
	while(i < *tablen_a)
		{
			if((*tab_a)[i]<min)
			{
				index_min = i;
				min = (*tab_a)[i];
			}
			else if((*tab_a)[i]>max)
			{
				index_max = i;
				max = (*tab_a)[i];
			}
			i++;
		}
	printf("min = %d\n", min);
	printf("max = %d\n", max);
		

	while(1)
	{
		i = 0;
		if(checker(*tab_a, tablen_a) == 0)
			{
				printf("tri effectueeeee\n");
				return;
			}
		if((*tab_a)[0] > (*tab_a)[1] && (*tab_a)[0] != max && (*tab_a)[0] != min)
		{
			pb(*tab_a, tab_b, tablen_a, tablen_b);
			compteur++;
		}
		// else if((*tab_a)[0] > (*tab_a)[1] && (*tab_a)[0])

		



	}
	printf("compteur ================== %d\n", compteur);
}
 */

/* void	tri(int **tab_a, int **tab_b, int *tablen_a, int *tablen_b)
{

	int i = 0;
	int index_min = 0;
	int index_max = 0;
	int test = 0;
	int compteur = 0;
	int min_a;
	int max_a;
	int min_b;
	int max_b;
	// while(i < *tablen_a)
	// 	{
	// 		if((*tab_a)[i]<min_a)
	// 		{
	// 			index_min = i;
	// 			min_a = (*tab_a)[i];
	// 		}
	// 		else if((*tab_a)[i]>max_a)
	// 		{
	// 			index_max = i;
	// 			max_a = (*tab_a)[i];
	// 		}
	// 		i++;
	// 	}
	// printf("min = %d\n", min_a);
	// printf("max = %d\n", max_a);
		

	while(*tablen_a > 1)
	{
		i = 0;
		// if(checker(*tab_a, tablen_a) == 0)
		// 	{
		// 		printf("tri effectueeeee\n");
		// 		return;
		// 	}

		pb(*tab_a, tab_b, tablen_a, tablen_b);
		compteur++;
	}
	min_a = (*tab_a)[0];
	max_a = (*tab_a)[0];
	min_b = (*tab_b)[0];
	max_b = (*tab_b)[0];
	while(*tablen_b>0)
	{
		// printf("%d\n", (*tab_b)[0]);

		// min_b = (*tab_b)[0];
		// max_b = (*tab_b)[0];

		if((*tab_b[0]) < min_a)
		{
			// printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
			while((*tab_a)[0] != min_a)
			{
				ra(*tab_a, tablen_a); // a ameliorer
				compteur++;
			}
			min_a = (*tab_b)[0];
			pa(tab_a, *tab_b, tablen_a, tablen_b);
			compteur++;
		}
		else if((*tab_b[0]) > max_a)
		{
			// printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
			while((*tab_a)[0] != min_a)
			{
				ra(*tab_a, tablen_a);
				compteur++;
			}
			max_a = (*tab_b)[0];
			pa(tab_a, *tab_b, tablen_a, tablen_b);
			compteur++;
			// ra(*tab_a, tablen_a);
			
		}
		else
		{
			// printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
			test = min_a;
			i=0;
			while(i<*tablen_a)
			{
				if((*tab_a)[i]>test && (*tab_a)[i]<(*tab_b)[0])
				{
					test = (*tab_a)[i];
				}
				i++;
			}
			while((*tab_a)[0] != test)
			{
				ra(*tab_a, tablen_a);
				compteur++;
			}
			ra(*tab_a, tablen_a);
			compteur++;
			pa(tab_a, *tab_b, tablen_a, tablen_b);
			compteur++;
		}

		while((*tab_a)[0] != min_a)
			{
				ra(*tab_a, tablen_a);
				compteur++;
			}
		
		// pa(tab_a, *tab_b, tablen_a, tablen_b);
	}
	printf("COMPTEUR ================= %d\n", compteur);
}
 */
void	tri(int **tab_a, int **tab_b, int *tablen_a, int *tablen_b)
{
	// tri_three(tab_a, tablen_a);

	tri_four(tab_a, tab_b, tablen_a, tablen_b);


	// int min_a = (*tab_a)[0];
	// int i = 0;
	// int index_min_a = 0;
	// while(i < *tablen_a)
	// {
	// 	if((*tab_a)[i] < min_a)
	// 	{
	// 		min_a = (*tab_a)[0];
	// 		index_min_a = i;
	// 		// break;
	// 	}
	// 	i++;
	// }
	// // index_min_a = i;
	// printf("index_min_a = %d\n", index_min_a);

}

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
	// printf("************************************* \n");