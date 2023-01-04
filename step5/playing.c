#include<stdio.h>

int main()
{
	printf("Playing Computer\n");

	/*The first program's output I expected is sum=10*/

	int i = 1;
        int sum = 0;

    	while(i < 5)
    	{
        	sum += i;
        	i++;
   	 }

    	printf("sum=%d\n", sum);
	
	/*The second program's output I expected is 28.50000*/

	double q = 1;

    	for(i=1;  i<= 5;  i++)
    	{
        	q += i * i / 2.0;
    	}

    	printf("q=%f\n", q);

	/*The third program's output I expected is 2.000000*/

	q = 1;

    	do
    	{
       		q = q * 2;
    	} while(q < 0);

    	printf("q=%f\n", q);

	/*The fourth program's output I expected is 
	 *+
	 *++
	 *+++
	 *++++
	 *+++++
	 *++++++
	 *+++++
	 *++++
	 *+++
	 *++
	 *+
	 *---
	 * */
	
	int j;

	for(i=0;  i<11;  i++)
    	{
       		if(i < 5)
        	{
            		for(j=0;  j<=i;  j++)
                	printf("+");
        	}
        	else
        	{
            		for(j=0;  j<=(10-i);  j++)
                	printf("+");
        	}

        	printf("\n");
    	}

    	printf("---\n");
}
