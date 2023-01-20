// Problem Link -: https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/

// Solution

class Solution {
public:
    bool isPossible(vector<int>& v) {
        int n = v.size();
        vector <vector <int>> z ; 
        int p = v[0] , c = 1;
        for (int i=1;i<n;i++) {
            if (v[i]==p)  c++;
            else {
                z.push_back({p,c});
                p = v[i], c = 1;
            }
        }
        z.push_back({p,c});
        if (z.size() < 3) return false;
        for (int i=0;i<z.size();i++) {
            if (i-2 >=0 && z[i-1][0]+1==z[i][0] && z[i-1][1] >=z[i][1]) continue;
            if (i+2 <z.size() && z[i+1][0]-1==z[i][0] && z[i+1][1] >=z[i][1]) continue;
            if (i-1>=0 && i+1 <z.size() && z[i-1][0]+1==z[i][0] && z[i+1][0]-1==z[i][0] && min (z[i-1][1], z[i+1][1])>=z[i][1]) continue;
            if (i-2>=0 && i+2 <z.size() && z[i-1][0]+1==z[i][0] && z[i+1][0]-1==z[i][0] && min({z[i-2][1],z[i-1][1],z[i][1]})+min({z[i][1],z[i+1][1],z[i+2][1]}) >=z[i][1]) continue ;
            return false;
        }
        return true ;
    }
};