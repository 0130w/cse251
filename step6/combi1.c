#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 
 * Name : zzq
 * Program to determine combinations
 */

/*
 * 1.Function declaration
 * This tells the compiler about our functions
 * It must match the first line of the function defintion below
*/

int Factorial(int n);

int Binomial(int n,int k);

/* This is a function definition of a function called main that
 * takes no arguments and returns an integer. You've been writing
 * this function all along.
*/

int main()
{
    int n;
    int k;
    
    printf("Input n: ");
    scanf("%d", &n);
    if(n < 1)
    {
        printf("Must be greater than zero\n");
        exit(1);
    }
    
    printf("Input k: ");
    scanf("%d", &k);
    if(k < 0 || k > n)
    {
        printf("Must be between 0 and %d inclusive\n", n);
        exit(1);
    }
    
    printf("%d items taken %d ways is %d\n",n,k,Binomial(n,k));

}

/* 
 * 2. Function definition
 * This is where you tell what functions does.
*/

int Factorial(int n)
{
	int f = 1;
	for(int i=1;i<=n;++i)
	{
		f*=i;
	}
	return f;
}

int Binomial(int n,int k)
{
	if(n==k)
	{
		return 1;
	}	
	else if(k==0)
	{
		return 1;
	}
	else
	{
		return Binomial(n-1,k)+Binomial(n-1,k-1);
	}
}
