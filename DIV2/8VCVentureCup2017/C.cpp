//
// Created by RAHUL KUMAR SINGH on 15/01/17.
//


#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <math.h>
#include <queue>
using  namespace std;

#define FOR(a,b) for(int i=a;i<=b;i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define mp make_pair
#define pb push_back
#define FF first
#define SS second
#define PI 3.14159265
typedef long long int LL;
typedef int64_t i64;
bool visited[10005]={false};
vector<int> graph[10005];
void dfs(int root){
    for(int i=0;i<graph[root].size();i++){
        int child=graph[root][i];
        if(!visited[child]){
            visited[child]=true;
            dfs(child);
        }
    }
    return;
}
int main(){
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        graph[i].push_back(x);
        graph[x].push_back(i);
    }
    int count=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            visited[i]=true;
            dfs(i);
            count++;
        }
    }
    cout<<count<<"\n";
    return 0;
}
