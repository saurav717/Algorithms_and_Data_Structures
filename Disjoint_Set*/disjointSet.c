#include <stdio.h>
#include <stdlib.h>

int find(int);
void makeUnion(int, int);

int * level, * parent;

int find(int i)
{
	if(parent[i] != i)
		parent[i] = find(parent[i]);	
	return parent[i];	
}

void makeUnion(int set1, int set2)
{
	int set_r1 = find(set1);
	int set_r2 = find(set2);
	
	if(set_r1 != set_r2)
	{	
		if(level[set_r2]> level[set_r1])
		{
			parent[set_r1] = parent[set_r2];
			printf("The new parent of both of them is %d\n",(parent[set_r2] + 1));
		}

		else if(level[set_r2]<level[set_r1])
		{
			parent[set_r2] = parent[set_r1];
			printf("The new parent of both of them is %d\n",(parent[set_r1] + 1));
		}

		
		else
		{
			parent[set_r1] = parent[set_r2];
			level[set_r2]++;		
			printf("The new parent of both of them is %d\n",(parent[set_r2] + 1));
		}
	}
	else
		printf("The parent of both of them is %d\n",(parent[set_r2] + 1));
}

void main()
{
	int elemnum, choice, num1, num2;
	printf("Enter the number of elements,so the elements on which operations are done will be 1,2,3...number of elements\n");
	scanf("%d",&elemnum);
	
	level = (int*) malloc(sizeof(int)*elemnum);
	parent = (int*) malloc(sizeof(int)*elemnum);

	if(parent == NULL || level == NULL)
	{
		printf("Memory Overflow\n");
		return;
	}

	for(int i = 0; i < elemnum; i ++)
	{
		level[i] = 0;
		parent[i] = i;
	}

	while(1)
		{
			printf("Enter Choice\nMenu:\n1)Find\n2)Union \n3)exit\n\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1 : 	printf("Enter the no. to find parent\n");
							scanf("%d",&num1);
							if(num1> elemnum || num1 <1)
							{
								printf("The number is not present in the list\n");
								break;
							}
							num1 = find(num1 -1);
							printf("The parent is %d\n",(num1 + 1) );
							break;
						 
				case 2 :	printf("Enter the number which you want to union\n"	 );
							scanf("%d",&num1);
							scanf("%d",&num2);
							if(num1> elemnum || num1 <1 ||num2 > elemnum || num2 <1) 
							{
								printf("The number is not present in the list\n");
								break;
							}
							makeUnion(num1 -1,num2 -1);
							break;
								 
				case 3 : 	free(parent);
							free(level);
							return;
						 
				default: printf("Wrong Input\n");		 
			}
		}
}
