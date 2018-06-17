#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265358979323846264338327950288419716939937510L

// POROVNAVACI FUNKCE PRO RAZENI
int cmp(const long double * left, const long double * right)
{
	if(fabs(*left-*right)<1e-12L)
		return 0;
	if(*left>*right)
		return 1;
	return -1;
}

int main()
{
	// PRIPRAVA PROMENYCH
	int n=0;
	int current=0;
	int right=0; 
	int left=0; 
	int increase=0;
	int x=0;
	int y=0;
	long double phi=0;
	unsigned long int totalwrong=0;
	scanf("%d",&n);
	int ** Input=new int * [n];
	long double * InputTMP=new long double[n-1];
	for (int i=0;i<n;i++)
	{
		Input[i]=new int[2];
	}
	// VSTUP
	for (int i=0;i<n;i++)
		scanf("%d %d",&Input[i][0],&Input[i][1]);
	// VYPOCET
	for(int i=0;i<n;i++)
	{
		increase=0;
		current=0;
		right=0; 
		left=0;
		// VYPOCET UHLU OSTATNICH BODU PRO MOMENTALNI BOD
		for(int i2=0;i2<n;i2++)
		{
			phi = 0;
			if (i!=i2)
			{
				// VYPOCET UHLU VE STUPNICH
				x=Input[i2][0]-Input[i][0];
				y=Input[i2][1]-Input[i][1];
				if (x==0&&y>0)
					phi=0;
				if (x==0&&y<0)
					phi=180;
				if (y==0&&x>00)
					phi=90;
				if (y==0&&x<00)
					phi=270;
				if (x>0&&y>0)
					phi=(PI/2-atan2(fabs(y),fabs(x)))*180/PI;
				if (x>0&&y<0)
					phi=(PI/2+atan2(fabs(y),fabs(x)))*180/PI;
				if (x<0&&y>0)
					phi=(3*PI/2+atan2(fabs(y),fabs(x)))*180/PI;
				if (x<0&&y<0)
					phi=(3*PI/2-atan2(fabs(y),fabs(x)))*180/PI;
				InputTMP[increase]=phi;
				increase++;
			}
		}
		// SERAZENI UHLU
		qsort(InputTMP,n-1,sizeof(*InputTMP),(int (*)(const void *, const void *))cmp);
		// POCITANI BODU V INTERVALU
		while((InputTMP[current]<270+1e-12L)&&(right<n-1))
		{
			while((InputTMP[right]<InputTMP[current]+90-1e-12L)&&(right<n-1)) 
				if((right+1)<n-1)
					right++;
				else
					right=n-1;
			while((InputTMP[left]<=InputTMP[current]+270+1e-12L)&&(left<n-1))
				if((left+1)<n-1)
					left++;
				else
					left=n-1;
			totalwrong=totalwrong+(left-right);
			current++;
		}
	}
	// VYPIS VYSLEDKU
	unsigned long int totalgood=((unsigned long int)n-2)*((unsigned long int)n-1)*(unsigned long int)n/6;
	printf("%ld\n",totalgood-totalwrong);
	return 0;
}










