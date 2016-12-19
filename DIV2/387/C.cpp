//
// Created by RAHUL KUMAR SINGH on 19/12/16.
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
vector< pair<int, pair <int ,int > > > task; //[0] arrival time [1] server needed [2] time needed;
map<int,vector<int> > taskmap;
map<int,vector<int> >poptask;
class Compare
{
public:
    bool operator() (int a,int b)
    {
        if(a>b)
            return true;
        return false;
    }
};

std::priority_queue< int, std::vector<int>, Compare> server;
int main(){
    int n,q,x,y,z;
    cin>>n>>q;
    for(int i=0;i<q;i++){
       cin>>x>>y>>z;
        task.push_back(make_pair(x,make_pair(y,z)));
    }
    sort(task.begin(),task.end());
    for(int i=0;i<q;i++)
        cout<<task[i].first<<" "<<task[i].second.first<<" "<<task[i].second.second;
    long long int time=0;
    long long int tt=1;
    int taskc=q;
    int index=0;
    for(int i=1;i<=n;i++){
        server.push(i);
    }
  //  cout<<"honey";
    while((tt<1001010)&&(taskc>0)){
     //   cout<<"honey";
        if(task[index].first==tt){
            if(task[index].second.first<=server.size()) {
                int lc=task[index].second.first;
                int sersum=0;
                poptask[tt+task[index].second.second].push_back(index);
                while(lc){
                    sersum+=server.top();
                    taskmap[index].push_back(server.top());
                    server.pop();
                }
                cout<<sersum<<endl;
            }
            else{
                cout<<"-1"<<endl;
            }
            index++;
            taskc--;
        }
        else if(task[index].first<tt){
            // Invalid case ;
        }
        else if(task[index].first>tt){

        }
        tt++;
        if(poptask.find(tt)!=poptask.end()){
            for(int i=0;i<poptask[tt].size();i++){
                server.push(poptask[tt][i]);
            }
            poptask[tt].clear();
        }
    }

return 0;
}
