#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
  string str="hello";
  map<int,int>mp;
  for(int i=0;i<nums.size();i++){
    int x=target-nums[i];
    if(mp.find(x)!=mp.end()){
      mp[nums[i]]=i;
    }else{
      vector<int>ans;
      ans={mp[x],i};
      return ans;
    }
  }
        
}