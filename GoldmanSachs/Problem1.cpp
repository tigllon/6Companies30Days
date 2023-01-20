// Problem Link -: https://leetcode.com/problems/max-points-on-a-line/


// Solution 

class Solution {
public:
    int maxPoints(vector<vector<int>>& v) {
        int n = v.size();
        int ans = 1;

        auto solve  = [&] (int x,int y) {
            int sum = 0;
            for (int i=0;i<n;i++) {
                if ((v[i][1]-v[x][1])*(v[y][0]-v[x][0])== (v[y][1]-v[x][1])*(v[i][0]-v[x][0])) sum++;
            }
            ans  =max (ans , sum);
        };

        for (int  i=0;i<n;i++) {
            for (int j = i+1; j < n ; j++ ) solve (i,j);
        }
        return ans;
    }
};