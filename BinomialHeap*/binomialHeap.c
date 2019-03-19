#include <stdio.h>
#include <stdlib.h>

struct node
{
	int val, degree;
	struct node * parent , *right_sibl, * leftChild;
};

struct node * heap = NULL;

struct node * create(int);
struct node * find_min();
struct node * merge(struct node *, struct node *);
void linker(struct node *, struct node *);
struct node *union_h(struct node *,struct node *);
void insert(int);
void print(struct node *);
void deleteMin();

		struct node * find_min()
		{
			struct node * foundIn = heap, *traverser = heap;
			int min;

			if(heap == NULL)
				return NULL;
	
			min = heap->val;
	
			while(traverser != NULL)
			{
				if(min > traverser->val)
				{	
					min = traverser->val;
					foundIn = traverser;
				}	
				traverser = traverser->right_sibl;
			}
	
			return foundIn;
		}


		struct node * create(int Val)
		{
			struct node * 	pointer = (struct node *)malloc(sizeof(struct node));
			if(	pointer == NULL)
			{
				printf("Memory Overflow\n");
				exit(0);
			}
				pointer->val = Val ;
				pointer->degree = 0;
				pointer->parent = NULL;
				pointer->right_sibl = NULL;
				pointer->leftChild = NULL;
			return 	pointer;
		}


		struct node * merge(struct node * heap1,struct node * heap2)
		{

			struct node * tempHeap = NULL, *swap;

			if(heap1 == NULL)
			{
				return heap2;
			}
			
			else if(heap2 == NULL)
			{
				return heap1;
			}

			if(heap1->degree > heap2->degree)
			{
				tempHeap = heap2;
				heap2 = heap1;
				heap1 = tempHeap;
			}
			
			else
			{
				tempHeap = heap1;
			}

			while(heap1->right_sibl != NULL)
			{
				if(heap1 ->right_sibl->degree > heap2->degree)
				{
					swap = heap2;
					heap1 = heap1->right_sibl;
					heap1->right_sibl = swap;		
				}
				heap1 = heap1->right_sibl;
			}
			heap1->right_sibl = heap2;

			return tempHeap;
		}

		void linker(struct node * toBeLinked, struct node * linkedTo)
		{
			toBeLinked-> parent = linkedTo;
			toBeLinked-> right_sibl = linkedTo->leftChild;
			linkedTo->leftChild = toBeLinked;
			linkedTo->degree++;
		}

		struct node *union_h(struct node * heap1, struct node * heap2)
		{
			struct node * tempHeap = merge(heap1, heap2);
				if(tempHeap == NULL)
				return tempHeap;

			struct node * prev = NULL, *present = tempHeap, *next = present->right_sibl;
	
			while(next != NULL)
			{
				if((present->degree != next->degree)||(next->right_sibl != NULL && next->right_sibl->degree == present->degree) )
				{
					prev = present;
					present = next;
				}
				else 
				{
					if(present->val <= next->val)
					{
						present->right_sibl = next->right_sibl;
						linker(next, present);
					}
					else
					{
						if(prev == NULL) 
							tempHeap = next;
						else
							prev->right_sibl = next;
						linker(present, next);
						present = next;		
					}
				}
				next = present-> right_sibl;
			} 
			return tempHeap;

		}

		void insert(int Val)
		{
			struct node * newHeap = create(	Val);
			heap = union_h(heap,newHeap);
		}

		void print(struct node * hp)
		{
			if(heap == NULL )
				{
					printf("The heap is empty");
					return;
				}
	
			while(hp != NULL)
			{
				printf("%d ",hp-> val );
				print(hp->leftChild);
				hp= hp->right_sibl;
			}
		}

		void deleteMin()
		{
			struct node * foundIn = heap, *prev = NULL, *traverser = heap,*hNoMin = heap,*hMin = NULL;
			int min;
	
			if(heap == NULL)
			{
				return;
			}
	
			min = heap ->val;
			while(traverser->right_sibl != NULL)
			{
				if(min>traverser->right_sibl->val)
				{
					foundIn = traverser->right_sibl;
					prev = traverser;
					min = foundIn->val;
				}
				traverser = traverser ->right_sibl;
			}

			if(prev == NULL && foundIn->right_sibl ==NULL)
			{			
				hNoMin = NULL;
			}

			else if(prev == NULL)
			{
				hNoMin = foundIn->right_sibl;
			}
			
			else
			{
				prev->right_sibl = foundIn->right_sibl;
			}
			
			if(foundIn->leftChild != NULL)
			{
				struct node * next;
				traverser = foundIn->leftChild;
				prev = NULL;
				while(traverser != NULL)
				{
					next = traverser ->right_sibl;
					traverser->right_sibl = prev;
					prev = traverser;
					traverser = next;
				}
				hMin = prev;
				foundIn->leftChild = NULL;	
			}

			free(foundIn);
			heap =	union_h	(hNoMin,hMin);
		}

	int main()
	{
		int num;
		struct node * foundIn;
		while(1)
		{
			printf("1 - insert\n");
			printf("2 - find min\n");
			printf("3 - delete min\n");
			printf("4 - exit\n");

			printf("enter your choice\n");
			int c;

			scanf("%d",&c);
			switch(c)
			{
				case 1 : 	printf("Enter the no. to be inserted in the binomial heap\n");
							scanf("%d",&num);
							insert(num);
							print(heap);
							printf("\n");
							break;
						 
				case 2 :	foundIn = find_min();	
							if(foundIn == NULL)
								printf("The Heap is empty.\n");
							else
								printf("The minimum element is %d\n",foundIn->val);
							break;
								 
				case 3 :    deleteMin();
						    print(heap);
						    printf("\n");
						    break;
						
				case 4 :	return 0;		
							
				default: printf("Wrong Input\n");		 
			}
		}

}


