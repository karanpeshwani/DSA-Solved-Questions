#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums,int n, int startIndex,int & ans, int target){
        if((startIndex == n) and (target == 0)){
        // if((startIndex == nums.size()) and (target == 0)){
            ans += 1;
            return;
        }
        // else if(startIndex == nums.size()){
        else if(startIndex == n){
            return;
        }
        solve(nums,n, startIndex+1, ans, target + nums[startIndex]);
        solve(nums,n, startIndex+1, ans, target-nums[startIndex]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        int startIndex = 0;
        int n = nums.size();
        solve(nums,n,startIndex,ans, target);
        return ans;
    }
};