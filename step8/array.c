#include <stdio.h>

/* 
 * Name : <Insert name>
 * Program to experiment with arrays
 */
 
#define NumMovies 10
#define MaxGrosses 5

int main()
{
 	double gross[NumMovies] = {4633070, 3856195, 3171189, 1877685, 3251622, 3156594, 1629735, 2659234, 2028036, 510768};

	char *names[NumMovies] = {"Hall Pass", "Unknown", "I Am Number Four", "The King's Speech", "Just Go With It", "Gnomeo and Juliet", "Drive Angry","Justin Beiber:Never Say Never", "Big Mommas: Like Father, Like Son", "True Grit"};

	double sum;
	
	double highestGross = 0;
	
	int highestGrossIndex = 0;

	sum = 0;

	double maxGross[MaxGrosses] = {500000, 1000000, 2000000, 4000000, 10000000};

	int maxGrossIndex[MaxGrosses] = {-1,-1,-1,-1,-1};

	double maxGrossTemp;

	for(int i=0;i<MaxGrosses;++i)
	{
		maxGrossTemp = 0;
		
		for(int j=0;j<NumMovies;++j)
		{
			if(gross[j] < maxGross[i] && gross[j] > maxGrossTemp)
			{
				maxGrossIndex[i] = j;
				maxGrossTemp = gross[j];
			}
		}
	}

	for(int i=0;i<MaxGrosses;++i)
	{
		if(maxGrossIndex[i] == -1)
		{
			printf("No film made less than %.0f\n",maxGross[i]);
		}
		else
		{
			printf("The highest gross less than %.0f is %s at %.0lf\n",maxGross[i],names[maxGrossIndex[i]],gross[maxGrossIndex[i]]);
		}
	}

	for(int i=0;i<NumMovies;++i)
	{
		if(gross[i]>highestGross)
		{
			highestGrossIndex = i;
			highestGross = gross[highestGrossIndex];
		}
	}

	printf("The highest grossing film is: %s\n",names[highestGrossIndex]);

	for(int i=0;i<NumMovies;++i)
	{
		printf("Movie %2d %33s: %.0f\n",i+1,names[i],gross[i]);
	}

	for(int i = 0;i < NumMovies; ++i)
	{
		sum+=gross[i];
	}

	printf("Total gross for these fims was $%.0f\n",sum);	
}
