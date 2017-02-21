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


ULL n,l,r;

ULL getLimit(ULL n) {
    ULL st=2;
    while((n/2)>=1){
        st*=2;
        n=n/2;
    }
    return st-1;
}

ULL findOnes(ULL n, ULL si, ULL ei, ULL begin, ULL end ) {
    ULL mymid = n/2,modulo=n%2;
    ULL halfNup;
    halfNup= getLimit(mymid);
    if(end<si)
        return 0;
    if(begin>ei)
        return 0;
    if(begin>end)
        return 0;
    if(begin==end)
        return n==1?1:0;
    ULL myones = findOnes(mymid,si,ei,begin,begin+halfNup-1);
    ULL mid = (begin+end)/2;
    if(mid>=si && mid<=ei){
        myones+=(modulo%2==0?0:1);
    }
    myones+=findOnes(mymid,si,ei,begin+halfNup+1,end);
    return myones;
}
int main(){
    cin>>n>>l>>r;
    cout<<findOnes(n,l,r,1,getLimit(n));
    return 0;
}
