// Problem Link -: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/


// Solution 

class Solution {
public:
    int findUnsortedSubarray(vector<int>&v) {
        int n  = v.size();
        vector <int> t = v;
        sort(t.begin() , t.end());
        int i = 0;
        while (i < n && t[i]==v[i]) i++;
        if (i==n) return 0;
        int j = n-1;
        while (j >= i  && t[j]==v[j]) j--;
        return (j-i+1);
    }
};