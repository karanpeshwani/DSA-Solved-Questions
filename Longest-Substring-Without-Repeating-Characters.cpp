#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int n = s.size();
        
        int start = 0;
        int end = -1;
        int ans = 0;
        while(end != n-1){
            if(start > end){
                end++;
                set.insert(s[end]);
                ans = max(ans, (int) set.size());
            }
            else{
                end++;
                if(set.find(s[end]) == set.end()){    // not found in s
                    set.insert(s[end]);
                }
                else{                                 // found in s
                    end--;
                    set.erase(s[start]);
                    start++;
                }
                ans = max(ans, (int) set.size());
            }
        }
        return ans;
    }
};