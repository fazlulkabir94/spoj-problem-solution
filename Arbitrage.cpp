# include <iostream>
# include <cstdio>
# include <map>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    #endif // ONLINE_JUDGE
    int n,test=0;
    while(cin>>n){
        if(n == 0)
            break;
        map<string , int> mp;
        string a;
       for(int i=0;i<n;i++)
       {
        cin>>a;
        mp[a]=i;
       }
        int m;
        cin>>m;
        double data[50][50] , exchange;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                data[i][j] = 0.0;
            string s,d;
        for(int i = 0 ; i < m ; i++){
            cin>>s>>exchange>>d;
            int x , y;
            x = mp[s];
            y = mp[d];
            data[x][y] = exchange;
        }
        for(int k = 0 ; k < n ; k++)
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < n ; j++)
                        if(data[i][j]<data[i][k]*data[k][j])
                            data[i][j]=data[i][k]*data[k][j];
        bool flag = false;
        for(int i = 0 ; i < n ; i++){
                if(data[i][i] > 1.0 ){
                    flag = true;
                    break;
                }
        }
        if(flag)
            cout<<"Case "<<++test<<": Yes\n";
        else
            cout<<"Case "<<++test<<": No\n";
    }
    return 0;
}
