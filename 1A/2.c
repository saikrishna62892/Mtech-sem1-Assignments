#include<stdio.h>
int main()
{
int i,n;
char courses[100][7];
printf("Enter Number of Courses : ");
scanf("%d",&n);
fflush(stdin);
for(i=0;i<n;i++)
{
printf("Enter Course_code : ");
scanf("%s",courses[i]);
}
printf("\tCourse codes : \n");
for(i=0;i<n;i++)
printf("%s\n",courses[i]);
}

