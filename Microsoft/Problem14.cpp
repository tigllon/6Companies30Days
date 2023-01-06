// Problem Link -: https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/

// Solution 

class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
        int gcd = 0;
        for (auto &e : b) gcd = __gcd (gcd , e);
        sort (a.begin() ,a.end());
        for (int i=0;i<a.size();i++) if (gcd %a[i]==0) return i;
        return -1;
    }
};

