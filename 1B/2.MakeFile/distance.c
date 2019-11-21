#include<math.h>



double euclideandistance(int x1,int y1,int x2,int y2)
{

	int dx=x1-x2;
	int dy=y1-y2;
	return sqrt(dx*dx+dy*dy);


}


double cityblockdistance(int x1,int y1,int x2,int y2)
{

double dx,dy;
	 dx=abs(x1-x2);
	
	
	 dy=abs(y1-y2);
	return dx+dy;


}
