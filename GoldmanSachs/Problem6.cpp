// Problem Link -: https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/

// Solution

class Solution {
public:
    int minimumCardPickup(vector<int>& v) {
        unordered_map <int,int> m ;
        int ans  = 2e9;
        for (int i=0;i<v.size();i++) {
            if (m.count(v[i])) ans   = min (ans , i-m[v[i]]+1);
            m[v[i]] = i;
        }
        if (ans==2e9) ans  = -1;
        return ans;
    }
};