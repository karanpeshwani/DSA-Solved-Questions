#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x == 0) return x;
        if(x > 0){
            string s = to_string(x);
            std::reverse(s.begin(), s.end());
            long long int rev = stoll(s);
            if(rev > pow(2, 31) - 1) return 0;
            return rev;
        }
        else{
            string s = to_string(x);
            int len = s.size();
            string s2 = s.substr(1, len-1);
            std::reverse(s2.begin(), s2.end());
            long long int rev = stoll(s2);
            if(rev > pow(2, 31)) return 0;
            return -1*rev;
        }
    }
};