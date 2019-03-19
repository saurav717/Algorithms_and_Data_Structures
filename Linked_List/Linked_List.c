#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node *next;
};

struct node *head = NULL;

void insert_node_at_end_of_list(int num)
{
	struct node *p, *q, *i;
	p = (struct node*)malloc(sizeof(struct node));

	p->val = num;
	p->next = NULL;

	if(head == NULL)
	{
		head = p;
	}

	else
	{

	for(q = head; q->next!=NULL; q=q->next)
	{
	}

	q->next = p;

	}
}

void insert_node_at_beginning_of_list(int num)
{
	struct node *l;
	l = (struct node*)malloc(sizeof(struct node));

	if(head == NULL)
	{
		head = l;
		l->val = num;
		l->next = NULL;
	}

	else
    {
    l->val = num;
	l->next= head;
    head = l;
    }
}

void insert_node_after_first_occuranceof_element(int num, int afnum)
{
	struct node *i, *j;
    j=(struct node*)malloc(sizeof(struct node));
    
    for(i=head;i!=NULL;i=i->next)
    {
    	if(i->val==afnum)
    	{
    		break;
    	}
    }

    if(i->val!=afnum)
    {
    	printf("number not found\n");
    	return;
    }

    j->val=num;
    j->next = i->next;
    i->next = j;
}

void del_last_repeating_number (int num)
{ 
	struct node *i, *j=NULL, *k=NULL;

	for(i=head;i!=NULL;i=i->next)
	{
		if(i->val==num)
		{
			j=i;
		}
	}

	if(j==NULL)
	{
		printf("number not found\n");
		return;
	}

	for(i=head;i!=NULL;i=i->next)
	{
		if(i==j)
		{
			break;
		}
		k=i;  //k- previous wala node
	}

	if(k==NULL)
	{
		head=j->next;
		free(j);
		return;
	}

    k->next=j->next;
    free(j);
}

void delete_all_elements(struct node *i)
{
	while(head!=NULL)
	{
	i = head;
	head = i->next;
	free(i);
	}
}

void display(struct node *i)
{
	if(head==NULL)
	{
		printf("there are no elements in this list\n");
	}

	for(i=head; i!=NULL; i=i->next)
	{
		printf("%d  ", i->val );
	}

	printf("\n\n");
}

int main()
{
	int num, c, afnum;
	struct node *i;

	while(1)
	{
		printf("1 - insert a node at the end of the list\n");
		printf("2 - insert a node at the beginning of the list\n");
		printf("3 - insert node after the first occurance of an element\n");
		printf("4 - delete the last occurance of an element\n");
		printf("5 - delete all elements\n");
		printf("6 - print all elements\n");
		printf("7 - exit\n");
        
        printf("enter your choice\n");
		scanf("%d", &c);

		switch(c)
		{
			case 1:     printf("enter the number\n");
			            scanf("%d", &num);
			            printf("--------------------------------------\n");
			            insert_node_at_end_of_list(num);
			            printf("\n");display(i);break;
			            

			case 2:     printf("enter the number\n");
			            scanf("%d", &num);
			            printf("--------------------------------------\n");
			            insert_node_at_beginning_of_list(num);
			            printf("\n");display(i);break;

			case 3:     printf("enter the number you want to add\n");
			            scanf("%d", &num);
			            printf("enter the number after which you want to add\n");
			            scanf("%d", &afnum);
			            printf("--------------------------------------\n");
			            insert_node_after_first_occuranceof_element(num, afnum);
			            printf("\n");display(i);break;               

			case 4:     printf("--------------------------------------\n");
			            if(head==NULL)
			            {printf("the list is empty\n");break;}
			            printf("enter the number you want to delete\n");
			            scanf("%d", &num);
			            printf("--------------------------------------\n");
			            del_last_repeating_number(num);
			            printf("\n");display(i);break;

			case 5:     delete_all_elements(i);
			            printf("--------------------------------------\n");
			            printf("\n");display(i);break;

			case 6:     printf("--------------------------------------\n");
			            display(i);break;                                  

            case 7:     return 0;

			default:    printf("enter valid option\n");  
			            printf("--------------------------------------\n");

		}
	}
}