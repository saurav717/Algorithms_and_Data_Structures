#include <stdio.h>
#include <stdlib.h>

struct edgeNode
{
	int vertix1;
	int vertix2;
	int weight;
	
};

int * parent,*rank, numVertix,numEdges;
struct edgeNode * graph, *mst;

void swap(struct edgeNode * a, struct edgeNode *b)
{
	struct edgeNode temp = *a;
	*a = *b;
	*b = temp;
}

void minHeapify(int size, int index)
{
	
	int smallest = index, leftChild = (index*2) + 1, rightChild = (index*2) + 2;
	
	if((leftChild<size) && (graph[leftChild].weight > graph[index].weight))
		smallest = leftChild;
	if((rightChild<size) && (graph[rightChild].weight > graph[smallest].weight))
		smallest = rightChild;

	if(smallest != index)
	{
		swap(&graph[index],&graph[smallest]);		
		minHeapify(size,smallest);
	}

}

void buildMinHeap()
{
	for(int i = ((numEdges/2)-1); i>=0; i--)
		minHeapify(numEdges,i);
}

void heapsort()
{
	buildMinHeap();

	for(int i =numEdges-1; i>=1; i--) 
	{
		swap(&graph[0], &graph[i]);
		minHeapify(i,0); 
	}
}

void graphInput()
{
	printf("Enter the no. of vertices\n");
	scanf("%d",&numVertix);
	printf("Enter the number of edges\n");
	scanf("%d",&numEdges);
	
	if(numEdges< numVertix - 1)
	{
		printf("Number of edges cannot less than numVertix -1");
		exit(0);
	}
	graph = (struct edgeNode *)malloc(sizeof(struct edgeNode) *numEdges);
	
	printf("Now enter the edges(take vertix name as 0,1,2...) and there weights one by one in format : \nsource 0 \ndestination 2 \nweight 5\n");
	for(int i =0; i< numEdges; i++)
	{
		printf("\n\n");
		printf("Enter first node\n");
		scanf("%d",&graph[i].vertix1);
		printf("Enter second node\n"); 
		scanf("%d",&graph[i].vertix2);
		printf("Enter weight\n");
		scanf("%d",&graph[i].weight);
		if(graph[i].vertix1 == graph[i].vertix2)
		{
			printf("Source and destination vertices are same\n");
			exit(0);
		}
	}
}

int find(int i)
{
	if(parent[i] != i)
		parent[i] = find(parent[i]);
	return parent[i];	
}

void makeUnion(int set1, int set2)
{
	int set1Rep = find(set1);
	int set2Rep = find(set2);
	
	if(rank[set2Rep]> rank[set1Rep])
	{
		parent[set1Rep] = set2Rep;
		rank[set1Rep] += rank[set2Rep];
	}
	else if(rank[set2Rep]<rank[set1Rep])
	{
		parent[set2Rep] = set1Rep;
		rank[set2Rep] += rank[set1Rep];
	}
	else
	{
		parent[set1Rep] = set2Rep;
		rank[set1Rep] += rank[set2Rep];;	
	}
}

void kruskal()
{
	int traverser =0,v1Rep,v2Rep ;
	
	for(int edges = 0; edges < numVertix-1;)
	{
		v1Rep = find(graph[traverser].vertix1);
		v2Rep = find(graph[traverser].vertix2);
		
		if(v1Rep != v2Rep) 
		{
			mst[edges++] = graph[traverser];
			makeUnion(v1Rep,v2Rep);
		}
		traverser++;
	}

}
void main()
{
	graphInput();
	
	parent = (int *)malloc(sizeof( int) *numVertix);
	rank = (int *)malloc(sizeof( int) *numVertix);
	
	for(int i = 0; i <numVertix; i++)
	{
		parent[i] = i;
		rank[i] = 1;
	}
	
	heapsort();
/*	for (int i = 0; i < numEdges; ++i)
	{
		printf("%d %d %d\n",graph[i].vertix1,graph[i].vertix2,graph[i].weight);
	}*/
	
	mst =  (struct edgeNode *)malloc(sizeof(struct edgeNode) *(numVertix-1));
	
	kruskal();
	
	for(int i =0; i < numVertix-1; i++)
	{
		printf("%d %d %d\n",mst[i].vertix1,mst[i].vertix2,mst[i].weight);
	}
	printf("\n");	
	free(mst);
	free(graph);
	free(parent);
	free(rank);
}
