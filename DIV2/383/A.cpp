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

long long int modpow(long long int base, long long int  exp, long long int modulus) {
    base %= modulus;
    long long int result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}
int main ()
{
    long long int n;
    cin>>n;
    cout<<modpow(1378,n,10)<<endl;
}
