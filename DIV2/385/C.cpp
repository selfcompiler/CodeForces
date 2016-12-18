//
// Created by RAHUL KUMAR SINGH on 17/12/16.
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

typedef long long int LL;
int n,m,k;
int par[1004]={0};
int visit[1004]={0};
map<int , pair<int,int> > compsize;
map< pair <int,int>,bool > edge;
vector<int> graph[1004];
vector<int> govt;
//nodes, total_edges
pair<int,int> dfs(int node,int root){
    visit[node]=1;
    pair<int,int> ret,ret2;
    ret.first=1;
    ret.second=0;
    for(int i=0;i<graph[node].size();i++){
        int child=graph[node][i];
        par[child]=root;
        if(!edge[std::make_pair(min(node,child),max(node,child))]){
            ret.second+=1;
            edge[std::make_pair(min(node,child),max(node,child))]=true;
        }
        if(!visit[child]){
            ret2=dfs(child,root);
            ret.first+=ret2.first;
            ret.second+=ret2.second;
        }
    }
    return ret;
}
int main(){
    int g,x,y;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        cin>>g;
        govt.push_back(g);
        par[g]=g;
    }
    for(int i=0;i<m;i++){
        cin>>x>>y;
        edge[std::make_pair(min(x,y),max(x,y))]= false;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int maxsize=-10000000;
    int govid=-1;
    for(int i=0;i<govt.size();i++){
        compsize[govt[i]]=dfs(govt[i],govt[i]);
        if(maxsize<compsize[govt[i]].first){
            govid=govt[i];
            maxsize=compsize[govt[i]].first;
        }
    }
    int unvcount=0;
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            unvcount++;
        }
    }
    LL ans=0;
    LL te;
    LL tn;
    tn=compsize[govid].first+unvcount;
    te=(tn*(tn-1))/2;
    ans=te-compsize[govid].second;
    for(int i=0;i<govt.size();i++){
        if(govt[i]!=govid){
            tn=compsize[govt[i]].first;
            te=(tn*(tn-1))/2;
            ans+=(te-compsize[govt[i]].second);
        }
    }
    for(map< pair <int,int>,bool >::iterator it=edge.begin();it!=edge.end();it++){
        if(!(it->second))
            ans--;
    }
    cout<<ans<<endl;
    return 0;
}
