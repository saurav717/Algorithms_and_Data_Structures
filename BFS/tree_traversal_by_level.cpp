#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

using namespace std;


struct node{

	int val;
	struct node *left;
	struct node *right;
};

struct node *root = NULL;



void insert_in_position(struct node *p, struct node *q)
{
	if(p->val <= q->val)
	{
		if(q->left == NULL)
		{
			q->left = p;
		}

		else
		{ 	
			insert_in_position(p, q->left);
		}
	}

	else if(p->val > q->val)
	{
		if(q->right == NULL)
		{
			q->right = p;
		}

		else
		{
			insert_in_position(p, q->right);		
		}
	}
}



void insert(int num)
{
	struct node *p;
	p = (struct node *)malloc(sizeof(struct node));

	p->val = num;
	p->left = NULL;
	p->right = NULL;

	if(root == NULL)
	{
		root = p;
	}

	else
	{
		insert_in_position(p, root);
	}
}

void print(struct node *p)
{
	cout << p->val << " ";

	if(p->left!= NULL)
	{ 	
		print(p->left);
	}

	if(p->right!=NULL)
	{ 
		print(p->right);
	}

}

void BFS(struct node *p)
{

	vector<struct node *> level;
	vector<struct node *> next_level;

	level.push_back(p);

	while (!level.empty())
	{

		for (int i=0; i<level.size(); i++ )
		{ 
			struct node *q = level[i];
	
			cout << q->val << " " ;
			
			if(q->left!=NULL)
			{
				next_level.push_back(q->left);
			}

			if(q->right != NULL)
			{
				next_level.push_back(q->right);
			}

		}

		level = next_level;
		next_level.clear();
		cout << endl;
	}

}


int main()
{

	int num;

	insert(5);
	insert(3);
	insert(7);
	insert(1);
	insert(4);
	insert(6);
	insert(8);
	insert(9);
	insert(0);

	cout << "In-order printing for reference " << endl;


	print(root);

	cout << endl;

	cout << "by tree traversal" << endl;

	BFS(root);

}