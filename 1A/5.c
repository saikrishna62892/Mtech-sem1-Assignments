#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Array
{
char code[7];
char name[4];
int credits;
};
struct Array *ptr[4];
void getCredit()
{
int i;
char code[7];
printf("Enter Course_code to get credits : ");
scanf("%s",code);
for(i=0;i<4;i++)
if(strcmp(code,ptr[i]->code)==0)
printf("credits for %s : %d\n",code,ptr[i]->credits);
}
int main()
{
int i,ch;
char *filename,a1[7];
//Opening a file
filename=(char *)malloc(20*sizeof(char));
FILE *fp;
printf("Enter File name : ");
scanf("%s",filename);
fp=fopen(filename,"r");
//Array of Pointer
struct Array *obj;
obj=(struct Array*)malloc(4*sizeof(struct Array));
for(i=0;i<4;i++)
{
ptr[i]=(obj+i);
fscanf(fp,"%s",ptr[i]->code);
fscanf(fp,"%s",ptr[i]->name);
fscanf(fp,"%d",&ptr[i]->credits);
printf("%s %s %d\n",ptr[i]->code,ptr[i]->name,ptr[i]->credits);
}
getCredit();
}

