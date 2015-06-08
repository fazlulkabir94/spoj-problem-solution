# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;
# define MAX 104
# define inf 1000000000
int n,m;
char road[MAX][MAX];
int dp[MAX][MAX][MAX];
int cost( int row1 , int col1 , int row2,  int col2)
{
    if(row1==row2 && col1 == col2)
    {
        if(road[row1][col1]=='*')
            return  1 ;
        return 0;
    }
    int ans=0;
    if(road[row1][col1]=='*')
        ans++;
    if(road[row2][col2]=='*')
        ans++;
    return ans;
}
int solve(int row1,int col1,int row2)
{
	int col2=(row1+col1)-(row2);
	if(row1==n-1 and col1==m-1 and row2==n-1 and col2==m-1)
		return 0;
	if(row1>=n or col1>=m or row2>=n or col2>=m)
		return -1*inf;
	if(dp[row1][col1][row2]!=-1)return dp[row1][col1][row2];
	int ch1=-1*inf,ch2=-1*inf,ch3=-1*inf,ch4=-1*inf;
	if(road[row1][col1+1]!='#' and road[row2+1][col2]!='#')
		ch1=cost(row1,col1+1,row2+1,col2)+solve(row1,col1+1,row2+1);
	if(road[row1][col1+1]!='#' and road[row2][col2+1]!='#')
		ch2=cost(row1,col1+1,row2,col2+1)+solve(row1,col1+1,row2);
	if(road[row1+1][col1]!='#' and road[row2][col2+1]!='#')
		ch3=cost(row1+1,col1,row2,col2+1)+solve(row1+1,col1,row2);
	if(road[row1+1][col1]!='#' and road[row2+1][col2]!='#')
		ch4=cost(row1+1,col1,row2+1,col2)+solve(row1+1,col1,row2+1);
	return dp[row1][col1][row2]=max(ch1,max(ch2,max(ch3,ch4)));

}
int main()
{
 //freopen("in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {  
        scanf("%d %d",&m,&n);
       memset(dp,-1,sizeof dp);
        int res=0;
        for (int i=0; i<n; i++)
           scanf("%s",road[i]);
        if(road[n-1][m-1]=='#' || road[0][0]=='#'  )
            res=-1*inf;
        if(road[0][0]=='*')
            res++;
        road[0][0]='.';
        if(road[n-1][m-1]=='*')
            res++;
        road[n-1][m-1]='.';
        res+=solve(0,0,0);
        res=max(res,0);
        printf("%d\n",res);
    }
    return 0;
}
