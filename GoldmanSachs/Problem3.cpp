// Problem Link -: https://leetcode.com/problems/factorial-trailing-zeroes/description/

// Solution 

class Solution {
public:
    int trailingZeroes(int n) {
        int t = 0, f = 0;
        int v = 2;
        while (n/v > 0) t+=(n/v) ,  v*=2;
        v =5;
        while (n/v > 0) f+=(n/v) , v*=5;
        return min (t,f);
    }
};