#include<stdio.h>
#include<math.h>
#include<stdbool.h>

/*
 *Program to compute Fibonacci numbers
 */

int main()
{
	int fn1=1;//f(n-1)
	int fn2=0;//f(n-2)
	int f; //compute fibonacci number
	int i;//Loop counter

	/*Print the first two Fibonacci numbers*/
	printf("F(0) = 0\n");
	printf("F(1) = 1\n");

	/*Print 10 Fibonacci numbers*/

	for(i=2;i<=11;++i)
	{
		f= fn1+fn2;
		printf("F(%d) = %d\n",i,f);

		/*Update F(n-1) and F(n-2)*/
		fn2=fn1;
		fn1=f;
	}
}
