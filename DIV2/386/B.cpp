//
// Created by RAHUL KUMAR SINGH on 18/12/16.
//

//
// Created by RAHUL KUMAR SINGH on 18/12/16.
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

typedef long long int LL;
char str[2005];
char res[2005];
int cl,cr;
int main(){
    int n;
    cin>>n;
    cin>>str;
    int size=n;

    int index=0;

    if(n%2==0){
        cl=999;
        cr=1001;
        size--;
        res[1000]=str[0];
        index=1;
        bool f2=true;
        while(size){
            if(f2){
                res[cr]=str[index];
                f2=false;
                cr++;
            }
            else{
                res[cl]=str[index];
                f2=true;
                cl--;
            }
            index++;
            size--;
        }
    }
    else{
        size--;
        cl=999;
        cr=1001;
        index=1;
        res[1000]=str[0];
        bool f1=false;
        while(size){
            if(f1){
                res[cr]=str[index];
                f1=false;
                cr++;
            }
            else{
                res[cl]=str[index];
                f1=true;
                cl--;
            }
            index++;
            size--;
        }

    }
    for(int i=cl+1;i<cr;i++)
        cout<<res[i];
    cout<<endl;
    return 0;
}
