//
// Created by RAHUL KUMAR SINGH on 06/12/16.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <map>
#include <utility>
#include <set>
using  namespace std;
typedef long long int  LL;
LL arr[102][102]={0};
LL visited[104]={0};
LL parent[104]={0};
set<LL> cl;
LL gcd(LL a, LL b)
{
    if (b==0)
        return a;
    return gcd(b, a%b);
}
LL dfs(LL node,LL size,LL le){
    for(LL i=1;i<=size;i++){
        if(arr[node][i]){
            if(visited[i]){
                return le;
            }
            visited[i]=1;
            return dfs(i,size,le+1);
        }
    }
    return 0;
}

int main(){
    LL n,m,len;
    cin>>n;
    for(LL i=1;i<=n;i++){
        cin>>m;
        arr[i][m]=1;
        parent[m]++;

    }
    for(LL i=1;i<=n;i++){
        if(parent[i]>=2||parent[i]==0)
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    for(LL i=1;i<=n;i++){
        if(visited[i]==0){
            visited[i]=1;
            len=dfs(i,n,1);
            if(len==0){
                cout<<"-1"<<endl;
                return 0;
            }
           if(len%2==0)
               len=len/2;
           cl.insert(len);
        }
    }
    set<LL>::iterator it;
    LL ans;
    LL num;
    ans=*cl.begin();
    for(it=cl.begin();it!=cl.end();it++){
        num=*it;
        ans = ( ((num*ans)) /
                (gcd(num, ans)) );
    }

     cout<<ans<<endl;
    return 0;
}
