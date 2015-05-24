# include <stdio.h>
# define ll long long
int main()
{
    ll T,n,result;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        if(n%2==0)
        {
            result=((n*(n+2))*(2*n+1))/8;
             printf("%lld\n",result);
        }
        else
        {
                result=(((n*(n+2))*(2*n+1))-1)/8;
                 printf("%lld\n",result);
        }

    }
    return 0;

}
