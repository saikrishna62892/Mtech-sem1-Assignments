#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Array
{
char code[7];
char name[4];
int credits;
};
struct Array obj[100];
void getCredit()
{
int i;
char code[7];
printf("\nEnter Course_code to get credits : ");
scanf("%s",code);
for(i=0;i<4;i++)
if(strcmp(code,obj[i].code)==0)
printf("credits for %s : %d\n",code,obj[i].credits);
}
int main()
{
int i,courses;
printf("Enter Number of Courses : ");
scanf("%d",&courses);
printf("\n\tCourse Details : \n");
for(i=0;i<courses;i++)
{
printf("Enter Course_code : ");
scanf("%s",obj[i].code);
printf("Enter Course_name : ");
scanf("%s",obj[i].name);
printf("Enter Credits : ");
scanf("%d",&obj[i].credits);
printf("The Record %s %s %d Inserted Succesfully!!!\n",obj[i].code,obj[i].name,obj[i].credits);
}
printf("\tCourse Structure ");
for(i=0;i<courses;i++)
printf("\n%s %s %d",obj[i].code,obj[i].name,obj[i].credits);
getCredit();
}

