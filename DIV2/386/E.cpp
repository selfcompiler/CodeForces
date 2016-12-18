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
map<int,bool> odd;
map<int,bool> even;
vector<int> ri;
int array[200007];
int roll[200007]={false};
int fixnum[200007]={false};
int main(){
    int n,m,odupc,edupc,reqo,reqe,edc,odc,t,ec,oc;
    odupc=0;
    edupc=0;
    edc=0;
    odc=0;
    ec=0;
    oc=0;
    cin>>n>>m;
    t=n/2;
    for(int i=0;i<n;i++){
        cin>>array[i];
        if(array[i]%2){
            if(odd.find(array[i])==odd.end()){
                // not found
                odd[array[i]]=true;
                odc++;
                if(t>oc){
                    oc++;
                }
                else{
                    oc++;
                    ri.push_back(i);
                    fixnum[i]=true;
                }
            }
            else{
                odupc++;
                roll[i]=true;
                ri.push_back(i);
                fixnum[i]=true;
            }
        }
        else{
            if(even.find(array[i])==even.end()){
                // not found
                even[array[i]]=true;
                edc++;
                if(t>ec){
                    ec++;
                }
                else{
                    ec++;
                    ri.push_back(i);
                    fixnum[i]=true;
                }
            }
            else{
                edupc++;
                roll[i]=true;
                ri.push_back(i);
                fixnum[i]=true;
            }
        }
    }
    int octr=1;
    int ectr=2;
    int change=0;
    int evencounter=0;
    int oddcounter=0;
    for(int i=0;i<n;i++){
        if(!fixnum[i]){
            if(array[i]%2){
                oddcounter++;
            }
            else{
                evencounter++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(fixnum[i]){
            if(evencounter<t){
                while((even.find(ectr)!=even.end())&&(ectr<=m)){
                    ectr+=2;
                }
                if(ectr<=m){
                    array[i]=ectr;
                    even[ectr]=true;
                    ectr+=2;
                    change++;
                    fixnum[i]=false;
                    evencounter++;
                }
            }
            else if(oddcounter<t){
                while((odd.find(octr)!=odd.end())&&(octr<=m)){
                    octr+=2;
                }
                if(octr<=m) {
                    array[i] = octr;
                    odd[octr] = true;
                    octr+=2;
                    change++;
                    fixnum[i]=false;
                    oddcounter++;
                }
            }
        }
        if(fixnum[i]){
            cout<<"-1"<<endl;
            return 0;
        }
    }
    cout<<change<<endl;
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}
