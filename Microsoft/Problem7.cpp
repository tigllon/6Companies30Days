// Problem Link -: https://leetcode.com/problems/course-schedule/description/


// Solution

class Solution {
public:
    bool ans  = true;
    void dfs (vector <vector <int>> &g , vector <int> &v , int node)  {
        if (v[node]==1) {ans  = false; return ;}
        if (v[node]==2) return ;
        v[node] = 1;
        for (auto &e : g[node]) {
            dfs (g,v,e);
        }
        v[node] =2;
    }

    bool canFinish(int n, vector<vector<int>>& v) {
        vector <vector <int>> g (n);
        for (auto &e : v) g[e[0]].push_back(e[1]) ;
        vector <int> vis (n);
        for  (int i=0;i<n;i++)
        dfs (g,vis,i);
        return ans;
    }
};