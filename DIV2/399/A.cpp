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
map<ll,ll> st;
int main(){
    ll n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        st[x]++;
    }
    ll c=0;
    ll ans=0;
    ll last=0;
    for(map<ll,ll>::iterator iterator1=st.begin();iterator1!=st.end();iterator1++){
        if(c==0) {
            c++;
            continue;
        }
        ans+=iterator1->second;
        last=iterator1->second;
    }
    ans-=last;
    cout<<ans<<"\n";
    return 0;
}
