#include <stdio.h>
#define INF 999
void dijk(int adj[10][10],int n,int start)
{
	int cost[10][10];		// final cost matrix in this
	int visited[10];		// if a node is visited, value is set to 1, else 0
	int dist[10];			// distance betweem 2 nodes.
	int pred[10];
	int i,j,count,min,next;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(adj[i][j]==0)
			{
				cost[i][j]=INF;
			}
			else
			{
				cost[i][j]=adj[i][j];
			}
		}
	}
	for(i=0;i<n;i++)
	{
		dist[i]=cost[start][i];
		pred[i]=start;
		visited[i]=0;
	}
	dist[start]=0;
	visited[start]=1;
	count=1;
	while(count<n-1)
	{
		min=INF;
		for(i=0;i<n;i++)
		{
			if(dist[i]<min && !visited[i])
			{
				min=dist[i];
				next=i;
			}
		}
		visited[next]=1;
		for(i=0;i<n;i++)
		{
			if(!visited[i])
			{
				if((min+cost[next][i]) < dist[i])
				{
					dist[i]=min+cost[next][i];	
					pred[i]=next;
				}
			}
		}
		count++;
	}
	for(i=0;i<n;i++)
	{
		if(i!=start)
		{
			printf("The distance of node %d is %d\n",i,dist[i]);
			printf("Path is %d\n",i);
			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=start);
		}
		printf("\n");
	}
}
int main()
{
	int i,j,adj[10][10],n;
	printf("Enter number of vertices : ");
	scanf("%d",&n);
	printf("Enter the graph : \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&adj[i][j]);
		}
	}
	int start;
	printf("Enter the start vertex : ");
	scanf("%d",&start);

	dijk(adj,n,start);
	return 0;
}
