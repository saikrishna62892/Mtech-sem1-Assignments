#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Array
{
char code[7];
char name[4];
int credits;
struct List *regList;
};
struct Array *ptr[4];



struct List
{
char data[30];
struct List *link;
};
struct List *head[4];



void insert()
{
int i,index;
char code[7],name[30];
printf("Enter Course_code to Enter Student Details : ");
scanf("%s",code);
for(i=0;i<4;i++)
if(strcmp(code,ptr[i]->code)==0)
index=i;
struct List *node=(struct List*)malloc(sizeof(struct List));
if(head[index]==NULL)
{
head[index]=node;
node->link=NULL;
printf("Enter Name of the Student : ");
scanf("%s",node->data);
}
else
{
node->link=head[index];
head[index]=node;
printf("Enter the name of the Student : ");
scanf("%s",node->data);
}
ptr[index]->regList=head[index];
struct List *temp;
temp=head[index];
while(temp)
{
printf("%s-->",temp->data);
temp=temp->link;
}
}




void delete()
{
int i,index,count=0;;
char code[7],name[30];
printf("Enter Course_code to delete Student Details : ");
scanf("%s",code);
for(i=0;i<4;i++)
if(strcmp(code,ptr[i]->code)==0)
index=i;
if(head[index]==NULL)
printf("No Student data found!!");
else
{
struct List *temp,*p;
temp=head[index];
p=temp;					
printf("Enter Name of the Student to Delete : ");
scanf("%s",name);
while(strcmp(name,temp->data)!=0)
{
count++;
p=temp;
temp=temp->link;
}
if(count!=0)
{
if(temp->link!=NULL)
{
p->link=temp->link;
temp->link=NULL;
}
else if(temp->link==NULL)
p->link=NULL;
}
else
{
head[index]=temp->link;
temp->link=NULL;
ptr[index]->regList=head[index];
}

struct List *temp1;
temp1=head[index];
while(temp1)
{
printf("%s-->",temp1->data);
temp1=temp1->link;
}
}
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
for(i=0;i<4;i++)
head[i]=NULL;


//Options Menu
while(1)
{
printf("\n\t\tSTUDENT REGISTRATION MENU");
printf("\n1.Insert\n2.Delete\n3.Exit\nEnter your Choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1: insert();break;
case 2: delete();break;
case 3: exit(0);
default: printf("Please Enter Valid Choice!!!!");
}
}
}

