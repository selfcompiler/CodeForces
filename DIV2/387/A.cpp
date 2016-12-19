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
int main(){
    int n,a,b;
    cin>>n;
    a=1;
    b=n;
    for(int i=1;i*i<=n;i++){
        if((n%i)==0){
           a=n/i;
           b=i;
        }
    }
    cout<<min(a,b)<<" "<<max(a,b)<<endl;
    return 0;
}
