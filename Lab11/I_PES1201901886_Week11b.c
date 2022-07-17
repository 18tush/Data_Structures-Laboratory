#include<stdio.h>
#include "bfs.h"

int check_path(int **graph, int n, int v, int u)
{
	//TODO
	int g[n],z[n];
	int f=-1,r=-1;
	int i,num;
	for(i=0;i<n;i++)
		z[i]=0;

	r=r+1;
	g[r]=v;z[v]=1;
	while(f!=r)
	{
		f=f+1;
		num=g[f];
		z[num]=1;
		if(num==u)
			return 1;
		for(i=0;i<n;i++)
		{
			if(graph[num][i]==1 && z[i]==0)
			{
				z[i]=1;
				r=r+1;
				g[r]=i;
			}
		}
	}
	return 0;
}

