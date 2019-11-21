#include<string.h>
#include<stdio.h>
#include<stdlib.h>
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

//Insert Definition
void insertion()
{
	
	int i,j,index,p=0,q=0,len1,min,count1=0,r=0,s=0;
	char code[7],name[30],copy1[30],copy2[30],copy3[30];
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
		printf("%s-->",node->data);
	}
	else
	{
		struct List *temp1=head[index];
		struct List *prev;
		printf("Enter the Name of the Student : ");
		scanf("%s",node->data);
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
				if(copy1[p]==copy2[1])
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
			}				
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
		while(temp)
		{
			printf("%s-->",temp->data);
			temp=temp->link;
		}
	}//else
}//insert



//Delete Definition
void deletion()
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


