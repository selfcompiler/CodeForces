//
// Created by RAHUL KUMAR SINGH on 31/01/17.
//

#include<iostream>
#include <vector>
#include <set>
#include<algorithm>

using namespace std;
typedef int64_t i64;

i64 aDist[100];
vector<i64> DistanceDiffA;
vector<i64> DistanceDiffB;
i64 bDist[100];

int doMatch(int index, int len){
    int str=0;
    for(int i=index;i<len;i++){
        if(DistanceDiffA[i]!=DistanceDiffB[str++]){
            return 0;
        }
    }
    if(index>0){
        for(int i=0;i<index;i++){
            if(DistanceDiffA[i]!=DistanceDiffB[str++]){
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    i64 n,l;
    cin>>n>>l;
    int i;
    for(i=1;i<=n;i++){
        cin>>aDist[i];
    }
    for(i=1;i<=n;i++){
        cin>>bDist[i];
    }
    for(i=2;i<=n;i++){
        DistanceDiffA.push_back(aDist[i]-aDist[i-1]);
    }
    DistanceDiffA.push_back((l-aDist[n]+aDist[1]));
    for(i=2;i<=n;i++){
        DistanceDiffB.push_back(bDist[i]-bDist[i-1]);
    }
    DistanceDiffB.push_back((l-bDist[n]+bDist[1]));
    for(i=0;i<=(n-1);i++){
        if(doMatch(i,n)){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
