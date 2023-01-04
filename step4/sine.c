#include<stdio.h>
#include<math.h>
#include<stdbool.h>

/*
 *Simple program to experiment with looping
 * */

int main()
{
	double angle;
	int numSteps;
	do
	{
		scanf("%d",&numSteps);
	}while(numSteps<=2);

	double maxAngle = M_PI * 2;
	int i;
	double init_sinVal;
	double sinVal;
	char x = 92;
	for(i = 0;i<=numSteps;i++)
	{
		angle = (double)i/(double)numSteps * maxAngle;
		init_sinVal=sinVal;
		sinVal = sin(angle);
		printf("%3d: %5.2f %6.3f ",i,angle,sinVal);
		int space =(int)( 30 + sinVal*30);
		for(int i=1;i<=space;++i)
			printf(" ");
		if(fabs(cos(angle))<0.1)
		{
			printf("*\n");
			continue;
		}
		if(i==0)
		{
			printf("\\\n");
			continue;
		}
		if(sinVal > init_sinVal)
		{
			printf("\\\n");
		}
		else
		{
			printf("/\n");
		}
	}
}
