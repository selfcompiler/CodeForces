//
// Created by RAHUL KUMAR SINGH on 27/11/16.
//

#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(){
    int n,n1,n2,a,_min,_max,c;
    float v1,v2,ans;
    vector<int> val;
    cin>>n>>n1>>n2;
    for(int i=0;i<n;i++){
        cin>>a;
        val.push_back(a);
    }
    sort(val.begin(),val.end());
    v1=0;
    v2=0;
    _min=min(n1,n2);
    _max=max(n1,n2);
    c=_min;
    for(int i=n-1;i>=0&&c>0;i--,c--){
        v1+=val[i];
    }
    c=_max;

    for(int i=n-1-_min;i>=0&&c>0;i--,c--){
        v2+=val[i];
    }
    v1=v1/(1.0*_min);
    v2=v2/(1.0*_max);
    ans=0.0;
    ans=v1+v2;
    printf("%.7f",ans);
    return 0;
}
