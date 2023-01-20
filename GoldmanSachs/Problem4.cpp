// Problem Link -: https://leetcode.com/problems/number-of-boomerangs/description/

// Solution

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& v) {
        int n  =v.size();
        auto dis = [&] (int i ,int j) {
            return ((v[i][0]-v[j][0])*(v[i][0]-v[j][0])+ (v[i][1]-v[j][1])*(v[i][1]-v[j][1]));
        };
        int ans=0;
        for (int i=0;i<n;i++) {
            unordered_map <int,int>  m ;
            for (int j = 0;j < n ; j++) {
                if (i==j) continue ; 
                m[dis(i,j)]++;
            }
            for (auto &e : m) {
                ans+=(e.second)*(e.second-1);
            }
        }
        return ans;
    }
};