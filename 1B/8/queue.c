#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
struct Dlist *front=NULL,*rear=NULL,*temp2=NULL;
//IsEmpty Operation
int isEmpty(int index)
{
	if(top[index]==NULL)
	return 1;
	else
	return 0;
}
//Enqueue Operation
void Enqueue(int index)
{
	char dup1[30];
	struct Dlist *dnode=(struct Dlist*)malloc(sizeof(struct Dlist));
	if(isEmpty(index)==1)
	{
		printf("Enter Name of the Student to be in WaitingList : ");
		scanf("%s",dnode->data);
		strcpy(dup1,dnode->data);
		dnode->rlink=dnode->llink=NULL;
		temp2=front=rear=top[index]=dnode;
	}
	else
	{
		printf("Enter Name of the Student to be in WaitingList : ");
		scanf("%s",dnode->data);
		strcpy(dup1,dnode->data);
		temp2->rlink=dnode;
		dnode->llink=temp2;
		dnode->rlink=NULL;
		rear=temp2=temp2->rlink;
	}
	struct Dlist *temp3=top[index];
	printf("\nWAITING LIST : \n");
	while(temp3)
	{
		printf("%s---",temp3->data);
		temp3=temp3->rlink;
	}
	printf("\n");
}
//Dequeue Operation
void Dequeue(int index)
{
	char copy2[30],copy1[30],p=0,q=0,count1=0,min,len1,i;
	struct List *node=(struct List*)malloc(sizeof(struct List));
	strcpy(node->data,front->data);
	if(isEmpty(index)!=1)
	{
		if(head[index]==NULL)
		{
			head[index]=node;
			node->link=NULL;
			printf("\nREGISTERED LIST : \n");
			printf("%s-->",node->data);
			printf("\n");
		}
		else
		{
		struct List *temp1=head[index];
		struct List *prev;
		strcpy(copy2,node->data);
		min=strlen(copy2);
		//list contains only 1 node
		if(temp1->link==NULL)
		{
			strcpy(copy1,temp1->data);
	   		len1=strlen(copy1);
			if(len1<min)
			min=len1;
			for(i=0;i<min;i++)
			{
				if(copy1[p]==copy2[q])
				{
					p++;
					q++;
				}
				if(copy1[p]>copy2[q])
				{
					node->link=temp1;
					head[index]=node;
					temp1=node;
					break;
				}
				if(copy1[p]<copy2[q])
				{
					temp1->link=node;
					node->link=NULL;
					break;
				}
			}//for				
		}//if
		//list contain many nodes
   		else
   		{
   			temp1=head[index];
   			prev=temp1;
			while(temp1)
       		{
       			p=0;
   	    		q=0;
       			count1=0;
       			strcpy(copy1,temp1->data);
       			len1=strlen(copy1);
       			if(len1<min)
       			min=len1;
				for(i=0;i<min;i++)
				{
    				if(copy1[p]==copy2[q])
    				{
    					p++;
    					q++;
    				}
    				if(copy1[p]>copy2[q])
    				{
    					count1=1;
    					node->link=temp1;
    					if(head[index]==temp1)
    					prev=node;
    					else
    					prev->link=node;
    					if(prev->link==head[index])
    					head[index]=prev;
    					break;
    				}
    				if(copy1[p]<copy2[q])
    				{
    					if(temp1->link!=NULL)
    					{
    						prev=temp1;
	    					temp1=temp1->link;
	    				}
    					else
    					{
	    					temp1->link=node;
	    					node->link=NULL;
	    					count1=1;
	    				}
	    				break;
    				}	
    			}//for
    			if(count1==1)
    			break;
       		}//while
		}//else
		//Printing List
		struct List *temp=head[index];
		printf("\nREGISTERED LIST :\n");
		}//else
		if(front!=rear)
		{
			top[index]=front=front->rlink;
			free(front->llink);
		}
		else
		{
			top[index]=NULL;
			free(front);
			front=rear=temp2=NULL;
		}
		
	}
	else
	{
		printf("\nWaiting List is Empty!!!");
		top[index]=NULL;
	}
	return;
}
