#include<stdio.h>
#include<math.h>
#include<stdbool.h>

/*
 * Simple lunar lander program.
 * By: zzq
 * Best landing: Time = 45 seconds, Fuel = 52.0, Velocity = -1.35
 * 
 */

int main()
{
	double altitude = 100; /*Meter*/
	double velocity = 0; /*Meters per second*/
	double burn; /*Amount of fuel to burn*/
	double power = 1.5; /*Acceleration per pound of fuel*/
	double fuel = 100;/* kilograms*/
	double g = -1.63;/*Moon gravity*/
	bool valid; /*Detect the value valid or not*/
	int count=0;/*total seconds you cost to land*/

	printf("Lunar Lander - (c) 2022, by zzq\n");
	
	do
	{
		printf("Altitude: %.2f\n",altitude);
		printf("Velocity: %.2f\n",velocity);
		printf("You have %.1f kilograms of fuel\n",fuel);

		
		do
		{
			valid = false;

			printf("How much fuel would you like to burn: ");
			scanf("%lf",&burn);	
			if(burn<0)
			{
				printf("You can't burn negative fuel\n");
			}
			else if (burn>5)
			{
				printf("You can't burn more than 5 kilograms of fuel per second\n");
			}
			else if (burn > fuel)
			{
				printf("You can't burn fuel you don't have\n");
			}
			else
			{	
				printf("Burning %.lf kilograms of fuel\n",burn);
				count++;
				valid = true;
			}
			}while(!valid);
			
			velocity = velocity + g + power*burn;

			altitude += velocity;

			fuel-=burn;
			
	}while(altitude>0);
	
	printf("You landed with a velocity of %.2f\n",velocity);

	if(fabs(velocity) > 3)
	{
		printf("Your next of kin have been notified\n");
	}
	else
	{
		printf("You live!\n");
		printf("The seconds you cost:%d\n",count);
		printf("The fuel you leave:%.2f\n",fuel);
	}

}
