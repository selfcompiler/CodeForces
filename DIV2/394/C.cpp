//
// Created by RAHUL KUMAR SINGH on 31/01/17.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <utility>
#include <set>
using  namespace std;
typedef long long int  LL;
#define INF 300000
int mymin(int a,int b){
    if(a>b)
        return b;
    else
        return a;
}
vector<string> given;
int dp[55][3]; // 0 - "special" , 1- numeric, 2 - alpha
bool isSpecial(char ch){
    if(ch=='&'||ch=='*'||ch=='#')
        return true;
    return false;
}
bool isNumeric(char ch){
    if(ch=='0'||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9')
        return true;
    return false;
}
bool isAlpha(char ch){
    if(ch>=97 && ch <=122)
        return true;
    return false;
}
void preprocess(){
    std::map<char ,int> charcost;
    for(int i=0;i<=54;i++)
        dp[i][0]=INF,dp[i][1]=INF,dp[i][2]=INF;
    for(int i=0;i<given.size();i++){
        charcost.clear();
        for(int j=0;j<given[i].length();j++){
            if(charcost.find(given[i][j])!=charcost.end()){
                charcost[given[i][j]]=mymin(charcost[given[i][j]],mymin(j,given[i].length()-j));
            }
            else{
                charcost[given[i][j]]=mymin(j,given[i].length()-j);
            }
        }
        for(std::map<char,int>::iterator it=charcost.begin();it!=charcost.end();it++){
            if(isSpecial(it->first)){
                dp[i][0]=mymin(dp[i][0],it->second);
            }
            if(isAlpha(it->first)){
                dp[i][2]=mymin(dp[i][2],it->second);
            }
            if(isNumeric(it->first)){
                dp[i][1]=mymin(dp[i][1],it->second);
            }
        }
    }
}
int solve(int i,int j,int k){
    int ans=INF;
    for(int x=0;x<=2;x++) {
        for (int y = 0; y <= 2; y++) {
            for (int z = 0; z <= 2; z++) {
                if(x!=y && y!=z && z!=x) {
                    ans = mymin(ans, dp[i][x] + dp[j][y] + dp[k][z]);
                }
            }
        }
    }
    return ans;
}
int main(){
    string str;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>str;
        given.push_back(str);
    }
    preprocess();
    int ans=INF;
    for(int i=0;i<given.size();i++){
        for(int j=i+1;j<given.size();j++){
            for(int k=j+1;k<given.size();k++){
                ans=mymin(ans,solve(i,j,k));
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
