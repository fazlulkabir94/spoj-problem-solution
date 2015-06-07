# include <iostream>
# include <cstdio>
# include <map>
# include <algorithm>
using namespace std;
# define ll long long
# define si(x) scanf("%d",&(x))
map<int,ll>dp;
ll f(int n)
{
	if(n==0)return 0;
	if(dp[n]!=0)return dp[n];
	ll ans=f(n/2)+f(n/3)+f(n/4);
	dp[n]=(ans>n)?ans:n;
	return dp[n];
}
int main()
{
	//freopen("in","r",stdin);
	int n;
	while(si(n)==1)
	{
		printf("%lld\n",f(n));
	}
	return 0;
}
