#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<stdlib.h>
/*
 *Simple program to compute factorial
 * */

int main()
{
	int f;
	printf("Number to compute the factorial of:");	
	scanf("%d",&f);
	int init_value=f;
	int fac=1;
	if(f<0)
		exit(1);
	while(f>0)
	{
		fac=fac*f;
		f--;
	}
	
	printf("%d! = %d\n",init_value,fac);
}
