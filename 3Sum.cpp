#include <bits/stdc++.h>
using namespace std;

/*
time - o(n^2)
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> st;
        vector<vector<int>> ans;
        for(int i=0;i <= n-3;i++){
            int req = -1*nums[i];
            int j = i+1;
            int k = n-1;
            cout<<"j : "<<j<<" k: "<<k<<endl;
            while (j<k)
            {
                if(nums[j] + nums[k] == req){
                    vector<int> v = {nums[i], nums[j], nums[k]};
                    st.insert(v);
                    j++;
                    k--;
                }
                else if (nums[j] + nums[k] > req)
                {
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        for(auto vec : st){
            ans.push_back(vec);
        }
        return ans;
    }
};




/*

// long approach
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        set<vector<int>> set;
        for(auto num : nums){
            mp[num]++;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1; j<n;j++){
                int sum2 = nums[i] + nums[j];
                mp[nums[i]]--;
                mp[nums[j]]--;
                
                if(mp[-1*sum2] > 0){
                    vector<int> v = {nums[i], nums[j], -1*sum2};
                    sort(v.begin(), v.end());
                    set.insert(v);
                }
                mp[nums[i]]++;
                mp[nums[j]]++;
            }
        }
        vector<vector<int>> ans;
        for(auto v : set){
            ans.push_back(v);
        }
        return ans;
    }
};
*/