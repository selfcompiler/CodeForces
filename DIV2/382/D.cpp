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
#include <cmath>

using namespace std;
typedef  long long int LL;
int modulo(int a,int b,int c){
    long long res = 1;
    for(int i=0;i<b;i++){
        res *= a;
        res %= c;
    }
    return res%c;
}

LL mulmod(LL a,LL b,LL c){
    LL x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

bool Fermat(LL p,int iterations){
    if(p == 1){ // 1 isn't prime
        return false;
    }
    for(int i=0;i<iterations;i++){
        // choose a random integer between 1 and p-1 ( inclusive )
        LL a = rand()%(p-1)+1;
        // modulo is the function we developed above for modular exponentiation.
        if(modulo(a,p-1,p) != 1){
            return false; /* p is definitely composite */
        }
    }
    return true; /* p is probably prime */
}
bool numberdivtest(LL p){
    LL l=1000;
    if(l<p)
        l=1000;
    else
        l=p-1;
    for(LL i=2;i<=l;i++){
        if(p%i==0){
            return false;
        }
    }
    return true;
}

bool Miller(long long p,int iteration){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}

int main()
{

    LL n;
    int ans;
    cin>>n;
    if(n%2==0){
        if(n==2)
            ans=1;
        else
            ans=2;
    }
    else if(Miller(n,18)){
        ans=1;
    }
    else if(Miller(n-2,18)){
        ans=2;
    }
    else{
        ans=3;
    }
    cout<<ans<<endl;

  return 0;
}
