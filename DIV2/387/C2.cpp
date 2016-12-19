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
#define all(v) v.beginarray(),v.end()
#define mp make_pair
#define pb push_back
#define FF first
#define SS second

typedef int64_t ULL;

ULL n,q;
ULL x,y,z;

int serverstart[101]={0};
int serverend[101]={0};
ULL t[1000001],k[1000001],d[1000001];
ULL beginarray[101];
ULL stopV[101];

int isgood(int beginarray_time,int end_time, int serv){
    int i;
    int cnt1=0;
    for(i=1;i<=n&&cnt1<serv;i++){
        if(beginarray[i] == 0 && stopV[i] == 0){
            cnt1++;
        }
        else{
            if(beginarray_time>=stopV[i])
                cnt1++;
        }
    }
    if(cnt1==serv)
        return 1;
    else
        return 0;

}

int run(int beginarray_time,int end_time, int serv){
    int sum=0;
    int i;
    int cnt1=0;
    for(i=1;i<=n&&cnt1<serv;i++){
        if(beginarray[i] == 0 && stopV[i] == 0){
            cnt1++;
            sum+=i;
            beginarray[i]=beginarray_time;
            stopV[i]=end_time;
        }
        else{
            if(beginarray_time>=stopV[i]){
                cnt1++;
                beginarray[i]=beginarray_time;
                stopV[i]=end_time;
                sum+=i;
            }
        }
    }
    return sum;

}


int main() {

    cin>>n>>q;

    int i;
    for(i=1;i<=q;i++){
        cin>>t[i]>>k[i]>>d[i];
    }

    for(i=1;i<=q;i++){
        int beginarray_time = t[i];
        int end_time=d[i];
        k[i];
        if(isgood(beginarray_time,beginarray_time+end_time,k[i])){
            cout<<run(beginarray_time,beginarray_time+end_time,k[i])<<endl;
        }
        else
            cout<<"-1"<<endl;
    }


}
