#include<stdio.h>
#include "./distance.h"


int main()
{
	int x1=2,x2=7,y1=10,y2=-23;
	
	printf("Euclidean distance:%f\n",euclideandistance(x1,y1,x2,y2));

	printf("City-Block distance:%f\n",cityblockdistance(x1,y1,x2,y2));

}
