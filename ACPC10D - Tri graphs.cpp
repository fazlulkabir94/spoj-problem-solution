# include <iostream>
# include <cstdio>
# include <algorithm>
using namespace std;
# define si(x) scanf("%d",&(x))
# define rep(i,n)for(int (i)=0;i<(n);i++)
# define re(i,n)for(int (i)=1;i<(n);i++)
# define inf 100000
# define Maxn 100001
int graph[Maxn][3];
int main()
{
	//freopen("in","r",stdin);
	int n,a,b,c,d,cnt=0;
	while(si(n)==1&&n) {
	rep(i,n)rep(j,3)si(graph[i][j]);
	graph[0][0]=inf;
	graph[0][2]+=graph[0][1];
	re(i,n)
	rep(j,3)
	{
		a=(j==2)?inf:graph[i-1][j+1];
		b=graph[i-1][j];
		c=(j==0)?inf:graph[i-1][j-1];
		d=(j==0)?inf:graph[i][j-1];
		graph[i][j]+=min(min(a,b),min(c,d));
	}
	printf("%d. %d\n", ++cnt, graph[n-1][1]);
}
return 0;
}
