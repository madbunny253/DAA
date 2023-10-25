#include<iostream>
#include <bits/stdc++.h>
//#include <climits>
using namespace std;
#define MAX 999

void displaygraph(int graph[][3],int E)
{
	cout<<"u\tv\tdist\n";
	for(int i=0;i<E;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<graph[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
}

void display_distance(int dist[],int V)
{
	cout<<"\nDISTANCE\n";
	for(int i=0;i<V;i++)
	{
		 cout<<dist[i]<<"\t";
	}

}


void bellman_ford(int graph[][3],int dist[],int V,int E)
{
		
	for(int i=0;i<V-1;i++)
	{
		for(int j=0;j<E;j++)
		{
			if( (dist[graph[j][0]] + graph[j][2] ) < dist[graph[j][1]] )
			{
				dist[graph[j][1]] =dist[graph[j][0]]+graph[j][2] ;
			
				
			}
		}
			display_distance(dist,V);	
	}
	
	
	for(int i=0;i<E;i++)
	{
		int x=graph[i][0]; 
		int y=graph[i][1]; 
		int weight=graph[i][2]; 
		if(dist[x]+weight<dist[y])
		{
			cout<<"\n\nGraph contains negative cycle";
		}
	}


	
	
/*	for (int i = 0; i < V-1 ; i++) {
 
        for (int j = 0; j < E; j++) {
            if (dist[graph[j][0]] != INT_MAX && dist[graph[j][0]] + graph[j][2] <dist[graph[j][1]])
                dist[graph[j][1]] =dist[graph[j][0]] + graph[j][2];
                  
        }
        display_distance(dist,V);
    }*/
    
    
   
	


}


int main()
{
	int V=5;
	int E=6;
	
	//int graph[E][3];
	
	int graph[E][3]={ {0,1,2},
		{0,2,4},
		{1,2,-4},
		{2,3,2},
		{3,4,6},
		{4,1,-1}};
	
	int dist[V];
	for(int i=0;i<V;i++)
	{
		 dist[i]=MAX;
	}
	 dist[0]=0;  //src
	 	
		
		displaygraph(graph,E);
		display_distance(dist,V);
		bellman_ford(graph,dist,V,E);
		
		
}
