#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"
#include"queue.h"

//Array Structure
int nodes[4]={0,0,0,0};
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


//Insert Definition
void insertlist()
{
	
	int i,index=1000,p=0,q=0,len1,min,count1=0;
	char code[7],name[30],copy1[30],copy2[30];
	printf("Enter Course_code to Enter Student Details : ");
	scanf("%s",code);
	for(i=0;i<4;i++)
	if(strcmp(code,ptr[i]->code)==0)
	index=i;
	if(i==4 && index==1000)
	{
		printf("Course Code doesn't Exist!!\n");
		return;
	}
	nodes[index]++;
	ptr[index]->regList=head[index];
	ptr[index]->waitList=top[index];
	if(nodes[index]<=ptr[index]->maxLimit)
	{
		if(isEmpty(index))
		{
			struct List *node=(struct List*)malloc(sizeof(struct List));
			//RegList creation
			if(head[index]==NULL)
			{
				head[index]=node;
				node->link=NULL;
				printf("Enter Name of the Student : ");
				scanf("%s",node->data);
				printf("\nREGISTERED LIST : \n");
				printf("%s-->",node->data);
				printf("\n");
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
				while(temp)
				{
					printf("%s-->",temp->data);
					temp=temp->link;
				}
				printf("\n");
			}//else
		}//Queue if
	}//nodes if
	else
	{
		//Wait List creation
		Enqueue(index);	
	}
}//insert




//Delete Definition
void deletelist()
{
	int i,index=1000,count=0;
	char code[7],name[30];
	printf("Enter Course_code to delete Student Details : ");
	scanf("%s",code);
	for(i=0;i<4;i++)
	if(strcmp(code,ptr[i]->code)==0)
	index=i;
	if(i==4 && index==1000)
	{
		printf("Course Code doesn't Exist!!\n");
		return;
	}
	nodes[index]--;
	if(head[index]==NULL)
	printf("No Student data found!!");
	else
	{
		struct List *temp,*p;
		temp=head[index];
		p=temp;					
		printf("Enter Name of the Student to Delete : ");
		scanf("%s",name);
		if(nodes[index]>=ptr[index]->maxLimit)
		{
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
			Dequeue(index);
		}//nodes if
		if(nodes[index]<ptr[index]->maxLimit)
		{
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
					free(temp);
				}
				else if(temp->link==NULL)
				{
					p->link=NULL;
					free(temp);
				}
			}
			else
			{
				head[index]=temp->link;
				free(temp);
				ptr[index]->regList=head[index];
			}
		}
		struct List *temp1;
		temp1=head[index];
		while(temp1)
		{
			printf("%s-->",temp1->data);
			temp1=temp1->link;
		}
		printf("\n");	
	}
}



//Display function
void display()
{
	char code[7];
	int i,index;
	printf("Enter Course_code to View Student Details : ");
	scanf("%s",code);
	for(i=0;i<4;i++)
	if(strcmp(code,ptr[i]->code)==0)
	index=i;
	struct List *a=head[index];
	struct Dlist *b=top[index];
	if(head[index]!=NULL)
	{
		printf("\nREGISTERED LIST :\n");
		printf("---------------------\n");
		while(a)
		{
			printf("%s-->",a->data);
			a=a->link;
		}
		printf("\n");
	}
	if(top[index]!=NULL)
	{
		printf("\nWAITING LIST :\n");
		printf("-----------------\n");
		while(b)
		{
			printf("%s---",b->data);
			b=b->rlink;
		}
	printf("\n");
	}
	if(head[index]==NULL && top[index]==NULL)
	printf("\nNo Student Record Found!!!\n");
}
