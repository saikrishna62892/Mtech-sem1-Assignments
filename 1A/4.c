#include<stdio.h>
#include<stdlib.h>
struct Array
{
char code[7];
char name[4];
int credits;
};
void CreateFile(struct Array obj[100],int courses)
{
int i;
char *filename,a1[7];
//Opening a file
filename=(char *)malloc(20*sizeof(char));
FILE *fp;
printf("\tFile Creation \nEnter File name : ");
scanf("%s",filename);
fp=fopen(filename,"w");
printf("Course Details :");
for(i=0;i<courses;i++)
{
fprintf(fp,"%s %s %d",obj[i].code,obj[i].name,obj[i].credits);
printf("\n%s %s %d",obj[i].code,obj[i].name,obj[i].credits);
}
printf("\nYour File created Successfully!!!\n");
}
int main()
{
int i,courses;
printf("Enter Number of Courses : ");
scanf("%d",&courses);
struct Array obj[100];
printf("\nCourse Details : \n");
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
CreateFile(obj,courses);
}

