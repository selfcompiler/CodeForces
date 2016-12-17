//
// Created by RAHUL KUMAR SINGH on 14/12/16.
//


#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <map>
#include <utility>
#include <set>
using  namespace std;
typedef long long int  LL;
int main(){
    int n,x,y,cost;
    char str[100005];
    cin>>n>>x>>y;
    cin>>str;
    if(str[x-1]==str[y-1]){
        cost=0;
    }
    else{
        cost=1;
    }
    cout<<cost<<endl;
    return 0;
}
