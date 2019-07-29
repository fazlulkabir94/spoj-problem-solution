#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

#define SIZE 50007

int a[SIZE] , par[SIZE];

struct SegmentTree{ int prefixSum , suffixSum ,Sum ,maxSum ; };

SegmentTree tree[ SIZE*3 ];

SegmentTree merge( SegmentTree a , SegmentTree b)
{
    SegmentTree res ;

    res.Sum = a.Sum + b.Sum ;

    res.prefixSum = max( a.prefixSum , a.Sum + b.prefixSum );

    res.suffixSum = max( b.suffixSum , b.Sum + a.suffixSum );

    res.maxSum = max( max( a.maxSum , b.maxSum ) , (a.suffixSum + b.prefixSum ) ) ;

    return res ;
}

void init(int node , int left , int right)
{
    if(left == right)
    {
        int X;  scanf("%d",&X);
        tree[node].prefixSum = tree[node].suffixSum = tree[node].Sum = tree[node].maxSum = X ;
        par[left] = node ;
        return ;
    }

    int _left = (node * 2) ;
    int _right = (node * 2) + 1;
    int _mid = (left + right ) / 2;

    init(_left, left, _mid);
    init(_right, _mid + 1, right);

    tree[node] = merge(tree[_left] , tree[_right] );
}


SegmentTree Query(int node , int left , int right , int i , int j)
{
    if(left == i && right == j) return tree[node];

    int _left = (node * 2) ;
    int _right = (node * 2) + 1;
    int _mid = (left + right ) / 2;

    if(j <= _mid) return Query(_left, left, _mid, i, j); // whole left side
    else if(i > _mid) return Query(_right, _mid+1, right, i, j) ; // whole right side
    else
        return merge(Query(_left, left, _mid, i, _mid) , Query(_right, _mid+1, right, _mid+1, j) ) ; // split in two side so merging
}
void Update(int i , int j)
{
    int node = par[i];

    tree[node].prefixSum = tree[node].suffixSum = tree[node].Sum = tree[node].maxSum = j ;

    node /= 2 ;
    while( node > 0 ) {
        int _left = (node * 2) ;
        int _right = (node * 2) + 1;
        tree[node] = merge(tree[_left], tree[_right]);
        node /= 2 ;
    }
}
int main()
{
    //freopen( "input.text" , "r" , stdin ) ;
    int N ;
    while(scanf("%d",&N)==1)
    {
        init(1,1,N);

        int Q ; scanf("%d",&Q);

        while(Q--)
        {
            int x , y , op ;
            scanf("%d %d %d",&op,&x,&y);
            if( op == 1 )
                printf("%d\n",Query(1,1,N,x,y).maxSum );
            else
                Update(x,y);
        }
    }
}
