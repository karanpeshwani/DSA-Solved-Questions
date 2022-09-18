#include <bits/stdc++.h>
using namespace std;

/*
backtracking
*/

class Solution {
public:
    void solve(unordered_map<int,vector<char>> mp,vector<string>& ans,string digits,int startIndex,int n,string temp){
        if(startIndex == n){
            ans.push_back(temp);
            return;
        }
        
        for(char c : mp[digits[startIndex] - 48]){
            solve(mp,ans, digits, startIndex + 1, n , temp + c);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n == 0) return {};
        vector<string> ans;
        unordered_map<int,vector<char>> mp;
        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[5] = {'j', 'k', 'l'};
        mp[6] = {'m', 'n', 'o'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};
        
        int startIndex = 0;
        string temp = "";
        solve(mp, ans, digits, startIndex, n, temp);
        return ans;
    }
};