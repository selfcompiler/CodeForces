//
// Created by RAHUL KUMAR SINGH on 15/01/17.
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
#include <math.h>
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
#define PI 3.14159265
typedef long long int LL;
typedef int64_t i64;
int main(){
    set<string> A,B;
    string str;
    int da,db,n,m,ac,bc,c;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>str;
        A.insert(str);
    }
    c=0;
    da=A.size();
    for(int i=1;i<=m;i++){
        cin>>str;
        if(A.find(str)!=A.end()){
            c++;
        }
        else{
            B.insert(str);
        }
    }
    da=da-c;
    db=B.size();
    if(c%2==0){
        if(da>db){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    else{
        da=da+1;
        if(da>db){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    return 0;
}
