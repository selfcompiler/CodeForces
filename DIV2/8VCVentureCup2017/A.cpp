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
bool isPrime(int n){
    if(n==2)
        return true;
    if(n==1)
        return true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=1000;i++){
        if(!isPrime(i*n+1)){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
