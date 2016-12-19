//
// Created by RAHUL KUMAR SINGH on 19/12/16.
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
char str[400];
int cou[256]={0};
int main(){
    int n,a,c,g,t;
    cin>>n;
    cin>>str;
    if(n%4){
        cout<<"==="<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        cou[str[i]]++;
    }
    a=n/4-cou['A'];
    c=n/4-cou['C'];
    g=n/4-cou['G'];
    t=n/4-cou['T'];
    if(a<0||g<0||c<0||t<0){
        cout<<"==="<<endl;
        return 0;
    }
    int size=n;
    int index=0;
    while((a>0||c>0||g>0||t>0)&&(size>0)){
        if(str[index]=='?'){
            if(a>0){
                str[index]='A';
                a--;
            }
            else if(c>0){
                str[index]='C';
                c--;
            }
            else if(g>0){
                str[index]='G';
                g--;
            }
            else if(t>0){
                str[index]='T';
                t--;
            }
        }
        index++;
        size--;
    }
    cout<<str<<endl;
    return  0;
}
