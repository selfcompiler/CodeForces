//
// Created by RAHUL KUMAR SINGH on 18/12/16.
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
int main(){
    LL n,k,a,b;
    int zero=1;// 1-mean A ,0-- mean B
    bool ismaxA,ismaxB,isminA,isminB;
    cin>>n>>k>>a>>b;
    LL minv,maxv;
    minv=min(a,b);

    maxv=max(a,b);
    if(a>b){
        zero=1;
        ismaxA=true;
        isminB=true;
        ismaxB= false;
        isminA=false;
    }
    else{
        zero=0;
        ismaxA=false;
        isminB=false;
        ismaxB= true;
        isminA=true;
    }
    if((maxv-minv*k)>k){
        cout<<"NO"<<endl;
        return 0;
    }
    int diff;
    while((a>0)||(b>0)){
        if(ismaxA){
            diff=a-b;
            for(int i=0;i<k&&diff>0;i++){
                diff--;
                a--;
                cout<<"G";
            }
            if(b){
                cout<<"B";
                b--;
            }
        }
        if(ismaxB){
            diff=b-a;
            for(int i=0;i<k&&diff>0;i++){
                diff--;
                b--;
                cout<<"B";
            }
            if(a){
                cout<<"G";
                a--;
            }
        }
    }
    return 0;
}
