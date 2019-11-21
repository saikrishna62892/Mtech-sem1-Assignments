#include<stdio.h>
int main()
{
int i,courses[100],n;
printf("Enter Number of Courses : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter Course_code : ");
scanf("%d",&courses[i]);
}
printf("\tCourse codes : \n");
for(i=0;i<n;i++)
printf("%d\n",courses[i]);
}

