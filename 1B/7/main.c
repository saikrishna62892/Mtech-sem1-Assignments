#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"
//Array Structure
struct Array
{
char code[7];
char name[4];
int credits;
struct List *regList;
};
struct Array *ptr[4];
//Single Linked List
struct List
{
char data[30];
struct List *link;
};
struct List *head[4];


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
			case 1: insertion();break;
			case 2: deletion();break;
			case 3: exit(0);
			default: printf("Please Enter Valid Choice!!!!");
		}
	}
}

