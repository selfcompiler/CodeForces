//
// Created by RAHUL KUMAR SINGH on 08/12/16.
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
pair<int,int> input[100005];
int n;
set<int> graph[200005];
int visited[200005];
int array[200005]={0};
void dfs(int node,int color){
    visited[node]=1;
    array[node]=color;
    set<int>::iterator it=graph[node].begin();
    for(;it!=graph[node].end();it++){
        if(!visited[*it]){
            dfs(*it,color^3);
        }
    }
}
int main(){
     cin>>n;
     for(int i=1;i<=n;i++){
         cin>>input[i].first>>input[i].second;
         graph[input[i].first].insert(input[i].second);
         graph[input[i].second].insert(input[i].first);
     }
    for(int i=1;i<=n;i++){
        graph[2*i].insert(2*i-1);
        graph[2*i-1].insert(2*i);
    }
    for(int i=1;i<=2*n;i++)
    {
        if(!visited[i])
            dfs(i,1);
    }
    for(int i=1;i<=n;i++){
        cout<<array[input[i].first]<<" "<<array[input[i].second]<<endl;
    }
    return 0;
}
