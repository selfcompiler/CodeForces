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
    int a,b,c,mc,mb;
    cin>>a;
       cin>>b;
          cin>>c;
    int ans=0;
    for(int i=0;i<=a;i++){
        mb=2*i;
        mc=4*i;
      //  cout<<mb<<" "<<mc<<endl;
        if((mb<=b)&&(mc<=c)){
            ans=max(ans,i+mb+mc);
        }
    }
    cout<<ans<<endl;
}
