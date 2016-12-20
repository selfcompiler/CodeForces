//
// Created by RAHUL KUMAR SINGH on 21/12/16.
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
const double pi = acos(-1.0);
const double eps1 = 1e-7;
const double eps2 = 1e-14;

struct set_comparator {
    bool operator() (const pair<int ,LL> &a, const pair<int ,LL> &b) const{
        return a.second>b.second;
    }
};
set< pair<int,LL> ,set_comparator> currentpeople;
vector< pair<int,LL> >removedpeople;
LL out[200005][2]={0};
vector<LL> people[200005];
int main(){
    int n,q,k,index,absentpeople;
    LL bidvalue;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>index>>bidvalue;
        people[index].push_back(bidvalue);
    }
    for(int i=1;i<=n;i++){
        if(people[i].size()){
            currentpeople.insert(std::make_pair(i,people[i][people[i].size()-1]));
        }
    }
    cin>>q;
    int counter=0;
    while(q--){
        cin>>k;
        for(int i=1;i<=k;i++){
            cin>>absentpeople;
            if(people[absentpeople].size())
            {
                currentpeople.erase(std::make_pair(absentpeople,people[absentpeople][people[absentpeople].size()-1]));
                removedpeople.push_back(std::make_pair(absentpeople,people[absentpeople][people[absentpeople].size()-1]));
            }
        }
        if(currentpeople.size()){
            if(currentpeople.size()==1) {
              //  cout << currentpeople.begin()->first << " " << people[currentpeople.begin()->first][0] << "\n";
                out[counter][0]=currentpeople.begin()->first;
                out[counter][1]=people[currentpeople.begin()->first][0];
            }
            else{
                pair<int, LL> answer=*currentpeople.begin();
                currentpeople.erase(answer);
                removedpeople.push_back(answer);
                pair<int ,LL> runnerup=*currentpeople.begin();
                int l=0,r=people[answer.first].size()-1;
                while(l<r){
                    int m=(l+r)/2;
                    if(people[answer.first][m]>runnerup.second){
                        r=m;
                    }else if(people[answer.first][m]<runnerup.second){
                        l=m+1;
                    }
                    if(l==r)
                        break;
                }
             //   cout<<answer.first<<" "<<people[answer.first][l]<<endl;
                out[counter][0]=answer.first;
                out[counter][1]=people[answer.first][l];
            }
        }
        else{
          //  cout<<"0 0\n";
            out[counter][0]=0;
            out[counter][1]=0;
        }
        for(vector< pair<int,LL> >::iterator it=removedpeople.begin();it!=removedpeople.end();it++){
            currentpeople.insert(*it);
        }
        removedpeople.clear();
        counter++;
    }
    for(int i=0;i<counter;i++){
        printf("%I64d %I64d\n",out[i][0],out[i][1]);
    }
    return 0;
}
