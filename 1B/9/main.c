#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"
#include"queue.h"
//Array Structure
//int nodes[4]={0,0,0,0};
struct Array
{
char code[7];
char name[4];
int credits;
int maxLimit;
struct List *regList;
struct Dlist *waitList;
};
struct Array *ptr[4];
//Single Linked List
struct List
{
char data[30];
struct List *link;
};
struct List *head[4];
//Double Linked List
struct Dlist
{
	struct Dlist *llink;
	char data[30];
	struct Dlist *rlink;
};
struct Dlist *top[4];
//struct Dlist *front=NULL,*rear=NULL,*temp2=NULL;


//Main function
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
	if(fp==NULL)
	{
		printf("\tFile Doesn't Exist in the Local Directory\n");
		exit(0);
	}
	//Array of Pointer
	struct Array *obj;
	obj=(struct Array*)malloc(4*sizeof(struct Array));
	printf("\t\tCode\tName\tCredits\tLimit\n");
	printf("\t\t-----------------------------\n");
	for(i=0;i<4;i++)
	{
		ptr[i]=(obj+i);
		fscanf(fp,"%s",ptr[i]->code);
		fscanf(fp,"%s",ptr[i]->name);
		fscanf(fp,"%d",&ptr[i]->credits);
		fscanf(fp,"%d",&ptr[i]->maxLimit);
		printf("\t\t%s\t%s\t%d\t%d\n",ptr[i]->code,ptr[i]->name,ptr[i]->credits,ptr[i]->maxLimit);
	}
	for(i=0;i<4;i++)
	{
		head[i]=NULL;
		top[i]=NULL;
	}
	//Options Menu
	while(1)
	{
		printf("\nSTUDENT REGISTRATION MENU");
		printf("\n-------------------------");
		printf("\n1.Insert\n2.Delete\n3.Display Lists\n4.Exit\nEnter your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insertlist();break;
			case 2: deletelist();break;
			case 3: display();break;
			case 4: exit(0);
			default: printf("Please Enter Valid Choice!!!!");
		}
	}
}

