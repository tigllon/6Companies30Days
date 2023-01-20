// Problem Link -: https://leetcode.com/problems/valid-square/description/


// Solution 

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector <vector <int>> a;
        a.push_back(p1);a.push_back(p2);a.push_back(p3);a.push_back(p4);
        auto dis = [&] (vector <int> &a , vector <int> &b) {
            return ((a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]));
        };
        vector <vector <int>> v (4);
        for (int i=0;i<4;i++) {
            for (int j=0;j<a.size();j++) {
                if (i==j) continue;
                v[i].push_back(dis (a[i],a[j]));
            }
            sort (v[i].begin(), v[i].end());
            if (v[i][0]==0) return false;
        }
        for (int j=0; j < 3; j++) {
            for (int i=1;i<4;i++) if (v[i-1][j]!=v[i][j]) return false;
        }
        if (v[0][0] !=v[0][1] || v[0][2]!=v[0][1]+v[0][0]) return false;
        return true;
    }
};