//
// Created by RAHUL KUMAR SINGH on 27/11/16.
//

#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef long long int LL;
int main(){
    int n,k,g,t,l,r;
    char str[160];
    cin>>n>>k;
    cin>>str;
    g=-1;
    t=-1;
    for(int i=0;i<n;i++){
        if(str[i]=='G')
            g=i;
        if(str[i]=='T')
            t=i;
    }
    l=min(g,t);
    r=max(g,t);
   // cout<<l<<" "<<r<<endl;
    if(l==r){
        cout<<"YES"<<endl;
        return  0;
    }
    int j=l;
    for(;j<=r;j+=k){
            if(str[j]=='#')
            {
                cout<<"NO"<<endl;
                return 0;
            }
            if(j==r){
                cout<<"YES"<<endl;
                return 0;
            }

    }
    if(j>r){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    return  0;
}
