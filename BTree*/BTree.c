#include<stdio.h>
#include<stdlib.h>

struct node
{
	int length;
	int B[5];
	struct node* C[6];
	int leaf;
	struct node* p;
};

struct node* root;

struct node* create(int val, int leaf)
{	
	int i;
	struct node* temp = (struct node *)malloc(sizeof(struct node));
	temp->leaf = leaf;
	temp -> B[0] = val;
	temp ->length = 1;
	for(i =0; i<6; i++)
	{
		temp -> C[i] = NULL;
	}
	
	return temp;
}

void display(struct node *ptr, int blanks){
    if (ptr)
    {
        int i;
        for(i=1; i<=blanks; i++)
            printf(" ");
        for (i=0; i < ptr->length; i++){
            printf("%d ",ptr->B[i]);
        }
        printf("\n");
        for (i=0; i <= ptr->length; i++)
            display(ptr->C[i], blanks+10);
    }
}

void insert(int val)
{	
	int i;
	struct node* new_node;
	if(root == NULL)
	{
		new_node =	create(val,1);
		root = new_node;
	}
	else
	{	
		struct node*x = root;
		while(! x-> leaf )
		{	
			for(i=0;i<x->length;i++)
			{
				if(x->B[i] > val)
				{
					break;
				}
			}
			
			x= x->C[i];
			
		}
		x->B[x->length] = val;
		int j = x->length - 1;
		while(j >= 0 && x->B[j] > val)
		{
			x->B[j+1] = x->B[j];
			j--;
		}
		
		x->B[j+1] = val;
		
		x->length ++;
		
		while(x->length == 5)
		{	
			struct node* parent = x->p;
			int prom = x->B[2];
			if(parent == NULL)
			{
				parent = create(prom,0); 
			}
			else
			{	
				int k=parent->length - 1;
				while(k >= 0 && parent->B[k] > prom)
				{
					parent->B[k+1] = parent->B[k];
					k--;
				}
				
				parent->B[k+1] = prom;
				parent -> length ++;
			}
			struct node* left, * right;
			if(x->leaf)
			{
				left = create(x->B[0],1);
				left->B[1] = x->B[1];
				right = create(x->B[3],1);
				right->B[1] = x->B[4];	
				
			}
			else
			{
				left = create(x->B[0],0);
				left->B[1] = x->B[1];
				right = create(x->B[3],0);
				right->B[1] = x->B[4];
			}
			
			left ->length = 2;
			right ->length = 2;
			right->p  = parent;
			left->p = parent;

			left->C[0] = x->C[0];
			if(x->C[0] != NULL)
			{
				x->C[0]->p = left;
			}
			left->C[1] = x->C[1];
			if(x->C[1] != NULL)
			{
				x->C[1]->p = left;
			}
			left->C[2] = x->C[2];
			if(x->C[2] != NULL)
			{
				x->C[2]->p = left;
			}
			right->C[0] = x->C[3];
			if(x->C[3] != NULL)
			{
				x->C[3]->p = right;
			}
			right->C[1] = x->C[4];
			if(x->C[4] != NULL)
			{
				x->C[4]->p = right;
			}
			right->C[2] = x->C[5];
			if(x->C[5] != NULL)
			{
				x->C[5]->p = right;
			}
			
			
			if(x == root)
			{
				parent -> C[0] = left;
				parent -> C[1] = right;
				root = parent;
				return;
			}

			int m = parent->length ;
			while(parent->C[m] != x)
			{
				parent->C[m+1] = parent->C[m];
				m--;
			}
			
			parent->C[m] = left;
			parent->C[m+1] = right;
			
			
			x= x ->p;
		}
		
		
		
		
	}
}

void print(struct node* z) //print b tree  
{
    if(z == root) printf("r : -> ");
    int i=0,j = 0;
    while(i< z ->length)
    {
        printf("%d ",z ->B[i]);
        i++;
    }
    printf("\n");
    
    while(j < z ->length +1)
    {
        if(z ->leaf) return;
        print(z ->C[j]);
        j++;
    }
}
struct node *find(int val) //search 
{
    struct node* z = root;
    int ind;
    while(z != NULL)
    {
        ind=0;
        while(ind < z ->length && val > z -> B[ind])
            ind++;
        if (val == z ->B[ind])
        {
            return z;
        }
        else
            z = z -> C[ind];
    }
    return NULL;
}
void left_borrow(struct node * x,int k)  //borrow from left child
{
	struct node* xP = x -> p;
	x ->B[x->length]=xP ->B[k];
    x ->length++;
    xP ->B[k]=xP ->C[k+1] -> B[0];
    x ->C[x ->length] = xP -> C[k+1] ->C[0];
    if(xP -> C[k+1] ->C[0] != NULL) xP -> C[k+1] ->C[0] ->p =x;
    int p=0;
    while(p < xP ->C[k+1] ->length -1)  
    {
        xP ->C[k+1] ->B[p] = xP ->C[k+1] ->B[p+1];
        xP -> C[k+1] -> C[p] = xP -> C[k+1] -> C[p+1];
        p++;
    }
    xP -> C[k+1] -> C[p] = xP -> C[k+1] -> C[p+1]; 
    xP ->C[k+1] ->length --;

}
void right_borrow(struct node * x,int k) //borrow from right child
{
	struct node* xP = x -> p;
	x ->length++;
    x -> B [1] = x ->B [0];
    x -> B[0] = xP -> B[k];

    xP ->B[k]=xP ->C[k-1] -> B[xP ->C[k-1] ->length -1];
    x -> C[0]=xP ->C[k-1] -> C[xP ->C[k-1] ->length];
    if(xP ->C[k-1] -> C[xP ->C[k-1] ->length] != NULL) 
        xP ->C[k-1] -> C[xP ->C[k-1] ->length] ->p =x;
    xP ->C[k-1] ->length --;

}

void left_merge(struct node * x,int k) //merge with left child
{
	struct node* xP = x -> p;	
	struct node * neighbour = xP ->C[k-1];
    neighbour -> B[2] = xP ->B[k-1];
    neighbour -> B[3] = x -> B[0];
    neighbour ->length = neighbour ->length +2;

    neighbour ->C[3]=x ->C[0];
    neighbour ->C[4]=x ->C[1];
    
    if(x ->C[0] != NULL)
        x ->C[0] ->p = neighbour;
    if(x ->C[1] != NULL)
        x ->C[1] ->p = neighbour;
	int i;
    for( i=k-1;i<xP ->length-1 ;i++)
    {
        xP ->B[i]=xP ->B[i+1];
        xP ->C[i+1]=xP ->C[i+2];
    }

    xP ->length --;
    if(xP -> length == 0)
    {
        root =neighbour;
        return;
    }

}

void right_merge(struct node * x,int k) //merge with right child only when all the other conditions fail i.e when its the leftmost child
{
	struct node * xP = x ->p;
	struct node * neighbour = xP ->C[1];
    x -> B[1] = xP ->B[0];
    x -> B[2] = neighbour -> B[0];
    x -> B[3] = neighbour ->B[1];

    x -> length = x -> length + 3;

    x -> C[2] = neighbour -> C[0];
    x -> C[3] = neighbour -> C[1];
    x -> C[4] = neighbour -> C[2];

    if(neighbour -> C[0] != NULL)
        neighbour -> C[0] ->p = x;
    if(neighbour -> C[1] != NULL)
        neighbour -> C[1] ->p = x;
    if(neighbour -> C[2] != NULL)
        neighbour -> C[2] ->p = x;
	int i;
    for(i=k;i<xP ->length-1 ;i++)
    {
        xP ->B[i]=xP ->B[i+1];
        xP ->C[i+1]=xP ->C[i+2];
    }

    xP ->length --;
   
}
void delete(struct node * x,int val) 
{
	int index=0; //finding required index 
    while(x ->B[index] != val)
        index++;

    if(x ->leaf) //if its a leaf 
    {
    	int i;
        for(i=index;i<x ->length;i++) //re arrange 
        {
            x ->B[i] = x ->B[i+1];
        }
        x ->length --; //update length
    }
    else
    {
        struct node *predecessor =x ->C[index]; //find its predecessor i.e 
        while(!predecessor->leaf)
        {
            predecessor = predecessor ->C[predecessor ->length];
        }
        x ->B[index] = predecessor -> B[predecessor ->length -1]; //updating the value 
        predecessor ->length --;
        x = predecessor;
    }

    while( x != root && x ->length < 2) //keep on going up untill there are less than 2 elements 
    {
        int k=0;
        struct node * xP =  x ->p;
        while(xP ->C[k] != x)
            k++;

        if(k < xP->length && xP ->C[k+1] -> length > 2) //the right neighbour contains enough elements ,then borrow from it
        {
            left_borrow(x,k);
            return;
        }
        else if(k > 0 && xP ->C[k-1] ->length > 2) //the left neighbour contains enough no of elements then borrow from it 
        {
            right_borrow(x,k);
            return;
        }
        else if(k>0 && xP ->C[k-1] ->length == 2) //if left neighbour contains two elements ,merge with it
        {
            left_merge(x,k);
        }
        else  //only possible if its the leftmost node
        {
            right_merge(x,k);
            if(xP -> length == 0)
            {
                root =x;
                return;
            }                            
        }
        x = x ->p; //updating x pointer for next iteration
    }

}


int main()
{
	root=NULL;
	int ch,item;
	while(1)
    {

        printf("B-tree: \n" );
        printf("1.Insert \n");
        printf("2.Delete \n" );
        printf("3.View \n");
        printf("4:Search\n");
        printf("5:Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {

        case 1:
            printf("Enter the value  \n");
            scanf("%d",&item);
            insert(item);
            break;

        case 2:
            printf("Enter the value \n");
            scanf("%d",&item);
            if(root ==NULL)
                printf("b Tree is empty\n");
            else if(find(item) != NULL)
                delete(find(item),item);
            else
                printf("Element not found in b tree \n");
            break;

        case 3:
            printf("Printing Tree\n");
            if(root ==NULL)
                printf("b Tree is empty\n");
            else
                display(root,0);
                // print(root);
            printf("\n");
            break;

        case 4:
            printf("Enter the value you want to search\n" );
            scanf("%d",&item);
            if(root ==NULL)
                printf("b Tree is empty\n");
            else if(find(item) != NULL)
                printf("Element found in b tree \n");
            else
                printf("Element not found in b tree \n");
            break;
        case 5:
            return 0;
        default:
            printf("Wrong choice\n");

        }
    }
   
}



















