//
// Created by RAHUL KUMAR SINGH on 20/02/17.
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
typedef int64_t ll;
typedef long long ULL;
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define mp make_pair
#define pb push_back
#define FF first
#define SS second
#define forn(i, n) for(ll i = 0; i < (ll)n; i++)
#define fornn(i, q, n) for(ll i = (ll)q; i < (ll)n; i++)

template <class T, class L> bool smax(T &x,L y){  return x < y ? (x = y, 1) : 0;  }
template <class T, class L> bool smin(T &x,L y){  return y < x ? (x = y, 1) : 0;  }

const double eps = 1e-8;
const double pi = acos(-1.0);
const ll inf = 1e17 + 7;
const int infi = 1e9 + 7;
const ll dd = 2e6 + 7;
const ll mod = 1e9 + 7;
ll arr[3][4004]={0};
ll n,k,x;
ll getCarry(ll tp,ll tss){
    ll l=tp+1;
    ll r=tp+tss;
    if(l%2==0)
        l++;
    if(r%2==0)
        r--;
    if(l>r)
        return 0;
    ll c=(r-l+2)/2;
    return c;
}
void doWork(ll idx,ll cidx){
    ll carry=0;
    ll tp=0;
    for(ll i=0;i<=4000;i++)
        arr[idx][i]=0;
    for(ll i=0;i<=4000;i++){
        if(arr[cidx][i]>0){
            carry=getCarry(tp,arr[cidx][i]);
            tp+=arr[cidx][i];
            arr[idx][i^x]+=carry;
            arr[idx][i]+=(arr[cidx][i]-carry);
        }
    }
}
int main(){
    cin>>n>>k>>x;
    ll lc;
    for(int i=0;i<n;i++){
        cin>>lc;
        arr[0][lc]++;
    }
    int nidx=1,idx=0;
    while(k>0){
        doWork(nidx,idx);
        idx=nidx;
        nidx=(nidx+1)%2;
        k--;
    }
    for(int i=4000;i>=0;i--)
        if(arr[idx][i]>0)
        {cout<<i<<" ";break;}
    for(int i=0;i<=4000;i++)
        if(arr[idx][i]>0)
        {cout<<i<<"\n";break;}
    return 0;
}
