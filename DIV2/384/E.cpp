//
// Created by RAHUL KUMAR SINGH on 17/12/16.
//

//
// Created by RAHUL KUMAR SINGH on 14/12/16.
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
#define neginf -1000000000
typedef long long int  LL;
typedef int64_t i64;
typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;
int dp[1005][(1<<8)+1]={neginf};
int array[1005];
vi in[9];
int cur[9]={0};

int ispossible(int len,int size){
    for(int i=0;i<=8;i++)
        cur[i]=0;
    for(int i=0;i<=(size+3);i++)
        for(int j=0;j<=(1<<8);j++)
            dp[i][j]=neginf;
    dp[1][0]=0;
    for(int i=1;i<=size;i++){
        for(int j=0;j<(1<<8);j++){
            if(dp[i][j]==neginf)
                continue;
            for(int k=0;k<8;k++){
                if(j&(1<<k))
                    continue;
                int it=cur[k+1]+len;
                if(it>in[k+1].size())
                    continue;
                dp[in[k+1][it-1]][j|(1<<k)]=max( dp[in[k+1][it-1]][j|(1<<k)],dp[i][j]);
                it++;
                if(it>in[k+1].size())
                    continue;
                dp[in[k+1][it-1]][j|(1<<k)]=max( dp[in[k+1][it-1]][j|(1<<k)],dp[i][j]+1);
            }

        }
        cur[array[i]]++;
    }
    int ans=neginf;
    FOR(1,size){
        ans=max(ans,dp[i][(1<<8)-1]);
    }
    if(ans<0)
        return -1;
   // cout<<"ans"<<ans<<" len"<<len<<endl;
    return ans*(len+1)+(8-ans)*len;
}
int main(){
    int n;
    S(n);
    FOR(1,n){
        S(array[i]);
        in[array[i]].pb(i);
    }
    int l=1,r=n/8;
    bool flag=false;
    while(r>=l){

 //        cout<<l<<" "<<r<<" "<<endl;
        int m=(l+r)/2;
        if(ispossible(m,n)!=-1){
            flag=true;
            l=m;
        }
        else{
            r=m;
        }
        if(((l+1)==r)||(l==r))
           break;
    }
    int ans;
    if(flag)
     ans=max(ispossible(l,n),ispossible(r,n));
    else
      ans=-1;
    if(ans==-1){
        ans=0;
        FOR(1,8){
            if(!in[i].empty()){
              ans++;
            }
        }
    }
    P(ans);
    return 0;
}
