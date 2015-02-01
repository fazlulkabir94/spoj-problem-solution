# include <iostream>
# include <cstdio>
# include <cstring>
# define ll long long
# define Size 100000
using namespace std;
ll N;
struct Bit
{
    ll bitarr[Size+1];
    Bit(int n)
    {
        N=n;
        memset(bitarr,0,sizeof(ll)*(N+1));
    }
    void intial(int n)
    {
        N=n;
        memset(bitarr,0,sizeof(ll)*(N+1));
    }
    ll quare(int idx)
    {
        ll s=0;
        while(idx>0)
        {
            s+=bitarr[idx];
            idx-=(idx&-idx);
        }
        return s;
    }
    void add(int idx,ll val)
    {
        while(idx<=N)
        {
            bitarr[idx]+=val;
            idx+=(idx&-idx);
        }
    }
    void update(int a,int b,ll val)
    {
        add(a,val);
        add(b+1,-val);
    }
};
int main()
{
    //freopen("in.text","r",stdin);
     Bit bit = Bit(Size);
     int t,n,u,q,a,b;
     ll val,k;
     scanf("%d",&t);
     while(t--)
     {
         scanf("%d %d",&n,&u);
         bit.intial(n);
         while(u--)
         {
             scanf("%d %d %lld",&a,&b,&val);
             a++;b++;
             if(b<a)
             {
                 swap(a,b);
             }
             bit.update(a,b,val);
         }
         scanf("%d",&q);
         while(q--)
         {
             scanf("%lld",&k);
             k++;
             printf("%lld",bit.quare(k));
             printf("\n");
         }
     }
    return 0;
}
