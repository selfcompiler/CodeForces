//
// Created by RAHUL KUMAR SINGH on 25/11/16.
//

#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef long long int LL;
#define SIZE 200001
struct node {
    LL weight;
    int constituency;
};
pair<node,vector<int> > arr[SIZE];
map< pair<int,int>, LL > edge_weight_map;
LL depth[SIZE]={0};
LL depth_sub_value[SIZE]={0};
int effect_count[SIZE]={0};
int lower_bound(LL array[],int lower,int higher,LL value){
    int mid;
    mid=(lower+higher)/2;
    while(lower<=higher){
        if(lower==higher){
            if(array[lower]<value)
                return lower;
            else
                return lower-1;
        }
        if((higher-lower)==1){
            if(array[higher]<value)
                return higher;
            if(array[lower]<value)
                return lower;
            return lower-1;
        }
        if(array[mid]<value){
            lower=mid;
        }
        else if(array[mid]>=value){
            higher=mid-1;
        }
        mid=(lower+higher)/2;
    }
    return lower;
}
void dfs(int vertex,int index){
    int childnode,lb;    //lb inclusive
    effect_count[index]=0;
    if(arr[vertex].second.size()==0){
        arr[vertex].first.constituency=effect_count[index];
        return;
    }
    for(int i=0;i<arr[vertex].second.size();i++)
    {
        childnode=arr[vertex].second[i];
        depth[index+1]=edge_weight_map[std::make_pair(vertex,childnode)]+depth[index];
        lb=lower_bound(depth,1,index,depth[index+1]-arr[childnode].first.weight);
        effect_count[index]+=1;
        effect_count[lb]-=1;
        dfs(childnode,index+1);
        effect_count[index]+=effect_count[index+1];
    }
    arr[vertex].first.constituency=effect_count[index];
    return;
}

int main(){
    int n,child,parent;
    LL edge_weight;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i].first.weight;
        arr[i].first.constituency=0;
    }

    for(int i=1;i<n;i++)
    {
        cin>>parent>>edge_weight;
        arr[parent].second.push_back(i+1);
        edge_weight_map[std::make_pair(parent,i+1)]=edge_weight;
    }
    depth[1]=0;
    effect_count[1]=0;
    dfs(1,1);
    for(int i=1;i<=n;i++)
        cout<<arr[i].first.constituency<<" ";
return 0;
}
