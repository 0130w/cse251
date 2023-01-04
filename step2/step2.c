#include<stdio.h>
#include<math.h>
/*
 *Name : 0130
 *
 *This is my first cse 251 C program
 * */
double radius = 7.88;
double height = 12.231;
int wins = 11;
int losses = 2;
double volume,diameter,hypot1;
int games;
double near = 10;
double far = 22.5;
int main()
{
	printf("The cylinder has a radius of %5.2f and a height of %8.1f\n",radius,height);

	printf("My first C program\n");

	printf("MSU had an %d-%d season in 2010!\n",wins,losses);

	volume = radius*radius*M_PI*height;

	games = wins + losses;

	hypot1 = sqrt(near*near+far*far);	

}
