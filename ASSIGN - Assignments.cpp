# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;
# define ll long long
# define si(x) scanf("%d",&(x))
# define rep(i,n) for(int (i)=0;i<(n);i++)
int N;
ll dp[(1<<20)];
int topic[20][20];
int main()
{
	//freopen("in","r",stdin);
	int test;
	si(test);
	while(test--)
	{
		si(N);
		rep(i,N)
		rep(j,N)
		si(topic[i][j]);
		fill(dp,dp+(1<<N)+1,0);
		dp[0]=1;
		int maxi=(1<<N);
		rep(mask,maxi)
		{
			int n=__builtin_popcount(mask);
			rep(i,N)
			if(topic[n][i]==1 && (mask&(1<<i))==0)
			dp[mask|(1<<i)]+=dp[mask];
		}
		printf("%lld\n",dp[maxi-1]);
	}
	return 0;
}
