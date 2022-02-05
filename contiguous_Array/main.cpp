leetcode:https://leetcode.com/problems/contiguous-array/

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
int findMaxLength(vector<int>& nums) {
    unordered_map<int,int> u1;
       for(int i=0;i<nums.size();i++){
           if(nums[i]==0){
               nums[i]=-1;
           }
       } 

       int sum=0,fin=0;
       for(int i=0;i<nums.size();i++){
           sum+=nums[i];
           if(sum==0){
               fin=max(fin,i+1);
           }
           else if(u1.find(sum)!=u1.end()){
               fin=max(fin,i-u1[sum]);
           }
           else{
               u1[sum]=i;
           }
       }
return fin;
}
int main(){
vector<int> v1;
int n;
cin>>n;
for(int i=0;i<n;i++){
    int h;
    cin>>h;
    v1.push_back(h);
}
cout<<findMaxLength(v1)<<endl;
}
