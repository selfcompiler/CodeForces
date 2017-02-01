//
// Created by RAHUL KUMAR SINGH on 31/01/17.
//


#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#include <map>
#include <utility>
#include <set>
using  namespace std;
typedef long long int  LL;
int main(){
    int a,b,d;
    cin>>a>>b;
    if(a>b)
        d=a-b;
    else
        d=b-a;
    if(a==0 && b==0){
        cout<<"NO\n";
        return 0;
    }
    if(d==0||d==1){
        cout<<"YES\n";
        return 0;
    }
    cout<<"NO\n";
    return 0;
}
