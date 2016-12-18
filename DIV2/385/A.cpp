//
// Created by RAHUL KUMAR SINGH on 17/12/16.
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

#define FOR(a,b) for(int i=a;i<=b;i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define mp make_pair
#define pb push_back
#define FF first
#define SS second
set<string> strse;
int main(){
    char str[108];
    cin>>str;
    int l=strlen(str);
    int j=l;
    for(int i=0;i<l;i++){
        str[j]=str[i];
        str[j+1]='\0';
        strse.insert(str+i);
        j++;
    }
    cout<<strse.size();
    return 0;
}
