#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//Array Structure
int count[4]={1,1,1,1},flag=0,nodes=0,heapcount[4]={0,0,0,0},avail[4]={0,0,0,0};
struct Array
{
char code[7];
char name[4];
int credits;
int maxLimit;
struct node *regList;
struct Heap *waitList;
};
struct Array *ptr[4];
//Node Structure
struct node
{
	char data[30];
	int count;
	struct node *left,*right,*parent;
}*roots[4]={NULL,NULL,NULL,NULL};
//Stack creation
struct node *stack[100];
int top=-1;
//Heap Structure
struct Heap
{
	char data[30];
	int priority;
}heap[4][100];
struct node *newnode(char name[30],int index)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	strcpy(temp->data,name);
	temp->count=count[index]++;
	temp->right=temp->left=NULL;
	return temp;
}
int getIndex()
{
	char code[7];
	int i,index;
	printf("Enter Course_code : ");
	scanf("%s",code);
	for(i=0;i<4;i++)
	if(strcmp(ptr[i]->code,code)==0)
	index=i;
	if(i==4 && index==100)
	{
		printf("\n\tCourse Code Doesn't Exist!!!");
		return;
	}
	return index;
}
void PrintHeap(int index)
{
	int i;
	struct Heap *temp=heap[index];
	if(heapcount[index]==0)
	{
		printf("\n\tHeap is Empty!!!\n");
		return;
	}
	for(i=0;i<heapcount[index];i++)
	printf("   %s %d   ",temp[i].data,temp[i].priority);
}
void maxheapify(struct Heap *temp,int i,int index)
{
	char dup[30];
	int l,r,largest,dupp;
	l=2*i+1;
	r=2*i+2;
	if(l<heapcount[index] && temp[l].priority>temp[i].priority)
	largest=l;
	else
	largest=i;
	if(r<heapcount[index] && temp[r].priority>temp[i].priority)
	largest=r;
	if(largest!=i)
	{
		strcpy(dup,temp[i].data);
		strcpy(temp[i].data,temp[largest].data);
		strcpy(temp[largest].data,dup);
		dupp=temp[i].priority;
		temp[i].priority=temp[largest].priority;
		temp[largest].priority=dupp;
		largest=i;
		maxheapify(temp,largest,index);
	}
}
void heapify(struct Heap *temp,int i,int index)
{
	char dup[30];
	int l,r,largest,dupp;
	l=2*i+1;
	r=2*i+2;
	if(l<=heapcount[index] && temp[l].priority>temp[i].priority)
	largest=l;
	else
	largest=i;
	if(r<=heapcount[index] && temp[r].priority>temp[i].priority)
	largest=r;
	if(largest!=i)
	{
		strcpy(dup,temp[i].data);
		strcpy(temp[i].data,temp[largest].data);
		strcpy(temp[largest].data,dup);
		dupp=temp[i].priority;
		temp[i].priority=temp[largest].priority;
		temp[largest].priority=dupp;
		largest=i;
		heapify(temp,(largest-1)/2,index);
	}
}
void Insertheap(int index,char name[30],int priority)
{
	int link,i;
	link=heapcount[index];
	struct Heap *temp=heap[index];
	if(priority>ptr[index]->maxLimit)
	{
		printf("\n\tPlease Enter Priority Range From 1 to %d !!!",ptr[index]->maxLimit);
		return;
	}
	if(link==0)
	{
		temp[link].priority=priority;
		strcpy(temp[link].data,name);
	}
	else
	{
		temp[link].priority=priority;
		strcpy(temp[link].data,name);
		heapify(temp,(link-1)/2,index);
	}
	printf("\nHEAP TREE : ");
	printf("\n----------\n");
	heapcount[index]++;
	PrintHeap(index);
	printf("\n");
}
void ExtractMax(struct Heap *temp,int index)
{
	char nam[30];
	int prior;
	if(heapcount[index]==0)
	{
		printf("\n\tHeap is Empty!!!\n");
		return;
	}
	strcpy(nam,temp[0].data);
	prior=temp[0].priority;
	printf("\nMAXKEY IN HEAP IS : %s %d\n",nam,prior);
	strcpy(nam,temp[heapcount[index]-1].data);
	strcpy(temp[heapcount[index]-1].data,temp[0].data);
	strcpy(temp[0].data,nam);
	prior=temp[heapcount[index]-1].priority;
	temp[heapcount[index]-1].priority=temp[0].priority;
	temp[0].priority=prior;
	heapcount[index]--;
	maxheapify(heap[index],0,index);
	printf("\nHEAP TREE : ");
	printf("\n----------\n");
	PrintHeap(index);
	printf("\n");
}
void IncreaseKey()
{
	char name[30];
	int index,increase,i,loc;
	index=getIndex();
	struct Heap *temp=heap[index];
	printf("Enter Name of the Student to increase Priority : ");
	scanf("%s",name);
	for(i=0;i<heapcount[index];i++)
	if(strcmp(name,temp[i].data)==0)
	loc=i;
	printf("Enter Increase Key Priority Value : ");
	scanf("%d",&increase);
	printf("\n\n\n%d",ptr[index]->maxLimit);
	if(increase<temp[loc].priority || increase>ptr[index]->maxLimit)
	{
		printf("\n\tThe Key Should be atleast as large as the current priority value!!!");
		return;
	}
	else
	temp[loc].priority=increase;
	maxheapify(heap[index],0,index);
	printf("\nHEAP TREE : ");
	printf("\n----------\n");
	PrintHeap(index);
	printf("\n");
}
void DecreaseKey()
{
	char name[30];
	int index,decrease,i,loc;
	index=getIndex();
	struct Heap *temp=heap[index];
	printf("Enter Name of the Student to increase Priority : ");
	scanf("%s",name);
	for(i=0;i<heapcount[index];i++)
	if(strcmp(name,temp[i].data)==0)
	loc=i;
	printf("Enter Decrease Key Priority Value : ");
	scanf("%d",&decrease);
	if(decrease>temp[loc].priority || decrease>ptr[index]->maxLimit)
	{
		printf("\n\tThe Key Should be atleast as small as the current priority value!!!");
		return;
	}
	else
	temp[loc].priority=decrease;
	maxheapify(heap[index],0,index);
	printf("\nHEAP TREE : ");
	printf("\n----------\n");
	PrintHeap(index);
	printf("\n");
}
void ChangeCourse()
{
	int indexo,indexn,prio,i;
	char name[30];
	printf("\nOld Course Details : ");
	printf("\n--------------------\n");
	indexo=getIndex();
	struct Heap *temp=heap[indexo];
	struct Heap p;
	printf("Enter Student Name :");
	scanf("%s",name);
	printf("\nNew Course Details : ");
	printf("\n--------------------\n");
	indexn=getIndex();
	for(i=0;i<heapcount[indexo];i++)
	if(strcmp(name,temp[i].data)==0)
	p=temp[i];
	strcpy(name,p.data);
	prio=p.priority;
	ExtractMax(&p,indexo);
	Insertheap(indexn,name,prio);	
}
void treeWalk(struct node *temp,int index)
{
	if(roots[index]==NULL)
	printf("\n\tTree is Empty!!!\n");
	if(temp)
	{
		treeWalk(temp->left,index);
		printf("   %s   ",temp->data,temp->count);
		treeWalk(temp->right,index);
	}
}
void ConversetreeWalk(struct node *temp,int index)
{
	if(roots[index]==NULL)
	printf("\n\tTree is Empty!!!\n");
	if(temp)
	{
		ConversetreeWalk(temp->right,index);
		printf("   %s   ",temp->data);
		ConversetreeWalk(temp->left,index);
	}
}
void printRegListASC()
{
	int i,index=100;
	char code[7];
	index=getIndex();
	printf("\nBINARY SEARCH TREE IN ASC ORDER : ");
	printf("\n--------------------------------\n");
	treeWalk(roots[index],index);
	printf("\n");
}
void printRegListDESC()
{
	int i,index=100;
	char code[7];
	index=getIndex();
	printf("\nBINARY SEARCH TREE IN DESC ORDER : ");
	printf("\n---------------------------------\n");
	ConversetreeWalk(roots[index],index);
	printf("\n");
}
void TreeSearch(struct node *temp,int index,int n)
{
	if(roots[index]==NULL)
	printf("\n\tTree is Empty!!!\n");
	if(temp)
	{
		TreeSearch(temp->left,index,n);
		if(nodes<n)
		{
			printf("   %s  ",temp->data);
			nodes++;
		}
		TreeSearch(temp->right,index,n);
	}
}
void TreeSearchb(struct node *temp,int index,int n)
{
	if(roots[index]==NULL)
	printf("\n\tTree is Empty!!!\n");
	if(temp)
	{
		TreeSearchb(temp->right,index,n);
		if(nodes<n)
		{
			printf("   %s  ",temp->data);
			nodes++;
		}
		TreeSearchb(temp->left,index,n);
	}
}
void printRegListN(int index)
{
	int w,n,i;
	struct node *dup;
	printf("Enter the Value of W (0 for top/1 for bottom) : ");
	scanf("%d",&w);
	if(w==0)
	{
		printf("Enter the Value n to get Top Students : ");
		scanf("%d",&n);
		printf("\nBINARY SEARCH TREE : ");
		printf("\n--------------------\n");
		TreeSearch(roots[index],index,n);
	}
	else if(w==1)
	{
		printf("Enter the Value n to get Bottom Students : ");
		scanf("%d",&n);
		printf("\nBINARY SEARCH TREE : ");
		printf("\n-------------------\n");
		TreeSearchb(roots[index],index,n);
	}
	else
	printf("\n\tPlease Enter Valid W Value!!!!");
}
void Tree_insert(struct node *root,struct node *temp,int index)
{
	int p=0,q=0,len,min,i;
	char copy1[30],copy2[30];
	struct node *prev=NULL;
	if(root==NULL)
	{
		root=temp;
		roots[index]=temp;
	}
	else
	{
		while(root!=NULL)
		{
			strcpy(copy1,root->data);
			strcpy(copy2,temp->data);
			min=strlen(copy1);
			len=strlen(copy2);
			if(len<min)
			min=len;
			for(i=0;i<min;i++)
			{
				if(copy1[p]==copy2[q])
				{
					p++;
					q++;
				}
				else if(copy1[p]>copy2[q])
				{
					prev=root;
					root=root->left;
					if(root==NULL)
					prev->left=temp;
					break;
				}
				else
				{
					prev=root;
					root=root->right;
					if(root==NULL)
					prev->right=temp;
					break;
				}
			}
		}
		temp->parent=prev;
	}
}
void Insert()
{
	int i,index=100,priority;
	char name[30],code[7],name2[30];
	index=getIndex();
	if(avail[index]<ptr[index]->maxLimit)
	{
		avail[index]++;
		printf("Enter Student Name : ");
		scanf("%s",name);
		struct node *temp=newnode(name,index);
		Tree_insert(roots[index],temp,index);
		printf("\nBINARY SEARCH TREE: ");
		printf("\n------------------\n");
		treeWalk(roots[index],index);
		printf("\n");
	}
	else
	{
		printf("Enter Student Name to Enter in WaitList : ");
		scanf("%s",name2);
		printf("Enter Priority of Student : ");
		scanf("%d",&priority);
		Insertheap(index,name2,priority);
	}
}
struct node *find=NULL;
struct node *get_pos(struct node *root,char *name)
{
	if(root)
	{
		if(strcmp(root->data,name)==0)
		{
			flag=1;
			return root;
		}
		else
		{
			struct node *find=get_pos(root->left,name);
			if(find==NULL)
			find=get_pos(root->right,name);
			return find;
		}	
	}
	else
	return NULL;
}
void Tree_delete(struct node *root,int index,char *name)
{
	int p=0,q=0,len,min,i;
	char copy1[30],copy2[30];
	struct node *dummy,*parent;
	root=get_pos(root,name);
	if(flag==0)
	{
		printf("\nStudent Not Found!!!\n");
		return;
	}
	if(root->left==NULL && root->right==NULL)
	{
		if(roots[index]==root)
		{
			roots[index]=NULL;
			free(root);
		}
		else
		{
			dummy=root->parent;
			strcpy(copy1,root->data);
			strcpy(copy2,dummy->data);
			len=strlen(root->data);
			min=strlen(dummy->data);
			if(len<min)
			min=len;
			for(i=0;i<min;i++)
			{
				if(copy1[i]==copy2[i])
				{
					p++;
					q++;
				}
				else if(copy1[p]<copy2[q])
				{
					dummy->left=NULL;
					break;
				}
				else
				{
					dummy->right=NULL;
					break;
				}	
			}
			count[index]--;
			free(root);
		}
	}
	else if(root->left==NULL || root->right==NULL)
	{
		if(root==roots[index])
		{
			if(root->left==NULL)
			{
				dummy=root->right;
				root->right=NULL;
			}
			else
			{
				dummy=root->left;
				root->left=NULL;
			}
			count[index]--;
			roots[index]=dummy;
			free(root);
		}
		else
		{
			if(root->left==NULL)
			{
				dummy=root->right;
				root->right=NULL;
			}
			else
			{
				dummy=root->left;
				root->left=NULL;
			}
			count[index]--;
			strcpy(root->data,dummy->data);
			free(dummy);
		}
	}
	else
	{
		struct node *succ,*parent;
		if(roots[index]==root)
		{
			strcpy(root->data,root->right->data);
			root->count=root->right->count;
			free(root->right);
			root->right=root->right->right;
		}	
		else
		{
			if(root->right!=NULL)
			{
				succ=root->right;
				while(succ->left)
				{
					parent=succ;
					succ=succ->left;
				}	
			}
			parent->left=NULL;
			strcpy(root->data,succ->data);
			count[index]--;
			free(succ);
		}
	}
	flag=0;
	printf("\nStudent Record Deleted Successfully!!!\n");
	treeWalk(roots[index],index);
	printf("\n");	
}
void Delete()
{
	int i,index=100;
	char name[30],code[7];
	index=getIndex();
	printf("Enter Student Name : ");
	scanf("%s",name);
	Tree_delete(roots[index],index,name);
}
int IsEmpty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
void push(struct node *temp)
{
		stack[++top]=temp;
}
struct node *pop()
{
	return stack[top--];
}
struct node *FindMaxKey(struct node *temp)
{
	struct node *dup;
	while(temp)
	{
		dup=temp;
		temp=temp->right;
	}
	return dup;
}
void TreeWalkStack(struct node *addr,int index)
{
	int done=0;
	char maxkey[30];
	if(addr==NULL)
	{
		printf("\n\tTree is Empty!!!\n");
		return;
	}
	while(!done)
	{
		while(addr)
		{
			push(addr);
			addr=addr->left;
		}
		while(IsEmpty()!=1)
		{
			addr=pop(addr);
			printf("   %s   ",addr->data);
			if(addr->right!=NULL)
			{
				addr=addr->right;
				break;
			}
			if(addr->right==NULL && IsEmpty())
			done=1;
		}
	}
}
void printRegListASC_Stack()
{
	int i,index=100;
	char code[7];
	index=getIndex();
	printf("\nBINARY SEARCH TREE IN ASC ORDER : ");
	printf("\n--------------------------------\n");
	TreeWalkStack(roots[index],index);
	printf("\n");
}
void TreeWalkStackConverse(struct node *addr,int index)
{
	int done=0;
	char maxkey[30];
	if(addr==NULL)
	{
		printf("\n\tTree is Empty!!!\n");
		return;
	}
	while(!done)
	{
		while(addr)
		{
			push(addr);
			addr=addr->right;
		}
		while(IsEmpty()!=1)
		{
			addr=pop(addr);
			printf("   %s   ",addr->data);
			if(addr->left!=NULL)
			{
				addr=addr->left;
				break;
			}
			if(addr->left==NULL && IsEmpty())
			done=1;
		}
	}
}
void printRegListDESC_Stack()
{
	int i,index=100;
	char code[7];
	index=getIndex();
	printf("\nBINARY SEARCH TREE IN DESC ORDER : ");
	printf("\n--------------------------------\n");
	TreeWalkStackConverse(roots[index],index);
	printf("\n");
}
void TreeWalkStackn(struct node *addr,int index,int n)
{
	if(addr==NULL)
	{
		printf("\n\tTree is Empty!!!\n");
		return;
	}
	while(nodes<n)
	{
		while(addr)
		{
			push(addr);
			addr=addr->left;
		}
		while(IsEmpty()!=1 && nodes<n)
		{
			addr=pop(addr);
			printf("   %s   ",addr->data,nodes);
			nodes++;
			if(addr->right!=NULL)
			{
				addr=addr->right;
				break;
			}
		}
	}
}
void TreeWalkStacknb(struct node *addr,int index,int n)
{
	if(addr==NULL)
	{
		printf("\n\tTree is Empty!!!\n");
		return;
	}
	while(nodes<n)
	{
		while(addr)
		{
			push(addr);
			addr=addr->right;
		}
		while(IsEmpty()!=1 && nodes<n)
		{
			addr=pop(addr);
			printf("   %s   ",addr->data);
			nodes++;
			if(addr->left!=NULL)
			{
				addr=addr->left;
				break;
			}
		}
	}
}
void printRegListN_Stack(int index)
{
	int w,n;
	printf("Enter the Value of W (0 for top/1 for bottom) : ");
	scanf("%d",&w);
	if(w==0)
	{
		printf("Enter the Value n to get Top Students : ");
		scanf("%d",&n);
		printf("\nBINARY SEARCH TREE : ");
		printf("\n-------------------\n");
		TreeWalkStackn(roots[index],index,n);
	}
	else if(w==1)
	{
		printf("Enter the Value n to get Bottom Students : ");
		scanf("%d",&n);
		printf("\nBINARY SEARCH TREE : ");
		printf("\n-------------------\n");
		TreeWalkStacknb(roots[index],index,n);
	}
	else
	printf("\n\tPlease Enter Valid W Value!!!!");
}
//Main function
int main()
{
	int i,ch,index=100,priority1;
	char *filename,code[7],name3[30];
	//Opening a file
	filename=(char *)malloc(20*sizeof(char));
	FILE *fp;
	printf("Enter File name (course.txt) : ");
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
		ptr[i]->regList=roots[i];
		ptr[i]->waitList=heap[i];
		printf("\t\t%s\t%s\t%d\t%d\n",ptr[i]->code,ptr[i]->name,ptr[i]->credits,ptr[i]->maxLimit);
	}
	//Options Menu
	while(1)
	{
		printf("\nSTUDENT REGISTRATION MENU");
		printf("\n-------------------------");
		printf("\n1.Insert()\n2.Delete()\n3.TreeWalk()\n4.PrintRegListASC()\n5.PrintRegListDESC()\n6.PrintRegListN()\n7.PrintRegListASC_Stack()\n8.PrintRegListDESC_Stack()\n9.PrintRegListN_Stack()\n10.PrintHeap()\n11.Insertheap()\n12.ExtractMax()\n13.IncreaseKey()\n14.DecreaseKey()\n15.ChangeCourse()\n16.Exit()\nEnter your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: Insert();break;
			case 2: Delete();break;
			case 3: 
			{
				index=getIndex();
				printf("\nBINARY SEARCH TREE : ");
				printf("\n-------------------\n");
				treeWalk(roots[index],index);
				printf("\n");
				break;
			}
			case 4: printRegListASC();break;
			case 5: printRegListDESC();break;
			case 6: 
			{
				index=getIndex();
				printRegListN(index);
				nodes=0;
				break;
			}
			case 7:printRegListASC_Stack();break;
			case 8:printRegListDESC_Stack();break;
			case 9:
			{
				index=getIndex();
				printRegListN_Stack(index);nodes=0;
			break;
			}
			case 10:
			{
				index=getIndex();
				printf("\nHEAP TREE : ");
				printf("\n----------\n");
				PrintHeap(index);
				printf("\n");
			break;
			}
			case 11:
			{
				index=getIndex();
				printf("Enter Student Name to Enter in WaitList : ");
				scanf("%s",name3);
				printf("Enter Priority of Student : ");
				scanf("%d",&priority1);
				Insertheap(index,name3,priority1);
				break;
			}
			case 12:
			{
				index=getIndex();
				ExtractMax(heap[index],index);
				break;
			}
			case 13:IncreaseKey();break;
			case 14:DecreaseKey();break;
			case 15:ChangeCourse();break;
			case 16: exit(0);
			default: printf("Please Enter Valid Choice!!!!");
		}
	}
}
