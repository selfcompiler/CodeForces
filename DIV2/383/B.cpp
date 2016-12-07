//
// Created by RAHUL KUMAR SINGH on 06/12/16.
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
typedef long long int LL;
long long int arr[1000009]={0};

int main(){
    long long int n,x,num,b,ans,rn;
    ans=0;
    cin>>n>>x;
    for(long long int i=1;i<=n;i++){
        cin>>num;
        rn=num^x;
        ans+=arr[rn];
        arr[num]++;
    }
    cout<<ans<<endl;
    return 0;
}
