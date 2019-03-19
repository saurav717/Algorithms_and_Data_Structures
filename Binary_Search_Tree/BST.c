#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bstNode {
	struct bstNode * child[2];
	int data ;
};

int found ;
struct bstNode * foundPtr;

struct bstNode * createBstNode()
{
	struct bstNode * p = (struct bstNode*)malloc(sizeof(struct bstNode));	
	
	if( p == NULL)
	{
		printf("Memory Overflow\n");
		return p ; 
	}
	
	printf("Enter num\n");
	scanf("%d",&p->data);
	printf("\n");
	p->child[0] = NULL;
	p->child[1] = NULL;
	return p; 
}

void printInorder(struct bstNode* root)
{
	if(root == NULL)
		return;
	printInorder(root -> child[0]);
	printf("data: %d\n",root->data);
	printInorder(root -> child[1]);
	
}

struct bstNode * insertBstNode(struct bstNode* root,struct bstNode* ptr)
{
	if(root == NULL)
		return ptr;
		
	else if((root->data) >= (ptr->data) )
		root ->child[0] = insertBstNode(root->child[0],ptr);
	
	else if((root->data) < (ptr->data) )
		root ->child[1] =	insertBstNode(root->child[1],ptr);
	
	return root;

}

void search(struct bstNode* root,int num)
{
	if(root == NULL)
	{	
		found = 0;
		return;
	}
	
	if(root ->data == num)
	{
		foundPtr = root;
		found = 1;
		return;
	}
	
	if(root->data < num)
	{
		search(root->child[1],num);
	}
	
	if(root->data >num)
	{
		search(root->child[0],num);
	}
}
struct bstNode * delete(struct bstNode* root, int num)
{
	if(root ==	NULL)
	{
		printf("The given data is not in the tree\n");
		return root;
	}

	else if(root ->data > num)
	{
		root ->child[0] = delete(root->child[0], num);
	}

	else if(root -> data <num)
	{
		root->child[1] = delete(root -> child[1], num);
	}

	else
	{

		if(root-> child[0] == NULL && root -> child[1] == NULL)
		{
			free(root);
			root = NULL;
		}
		
		else if( root -> child[1] == NULL)	
		{
			struct bstNode * temp = root;
			root = root ->child[0];
			free(temp);
		}
		
		else if(root ->child[0] == NULL)
		{
			struct bstNode * temp = root;
			root = temp ->child[1];
			free(temp);
		}
		else
		{
			struct bstNode * temp = root -> child[0];
			while(temp-> child[1] != NULL )
				temp = temp -> child[1];
			root->data	= temp-> data;
			root->child[0] = delete(root->child[0], temp-> data);
		}
	}
	return root;
}


int main()
{
	int choice, num;
	struct bstNode *ptr;
	struct bstNode *root = NULL;

	while(1)
	{
		printf("1 - insert\n");
		printf("2 - search\n");
		printf("3 - delete\n");
		printf("4 - exit\n");

		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :	ptr = createBstNode();
						if( ptr ==NULL )
							break;
						root = insertBstNode(root,ptr);
						printInorder(root);
						break;
					 
			case 2 : 	printf("Enter num\n");
						scanf("%d",&num);
						search(root,num);
						if(found == 0)
							printf("The given data is not in the tree\n");
						if(found == 1)
							printf("data: %d\n",foundPtr->data);	
						break;
						 
			case 3 :    printf("Enter data to be deleted\n");
					    scanf("%d",&num);
					    root =  delete(root, num);
					    printInorder(root);
					    break;
					
			case 4 :	return 0;
		 					
			default: printf("Wrong Input\n");		 
		}
	}
}



















































































































































































































































































































































































































































































































