// Problem Link -: https://leetcode.com/problems/most-profitable-path-in-a-tree/description/

// Solution 

class Solution {
public:

    void parent (vector <vector <int>> &g , int node , vector <int> &p,int par) {
        p[node] = par;
        for (auto &e : g[node]) if (e!=par)parent (g,e,p,node);
    }

    int dfs (vector <vector <int>> &g , int node , int time , vector <int> &p,vector <int> &t , vector <int> &a ,int par) {
        if (time <t[node]) p[node]+=a[node];
        else if (time==t[node]) p[node]+=a[node]/2;
        int mx  = -2e9;
        bool child = false;
        for (auto &e : g[node]) {
            if (e!=par)
            mx = max (mx , dfs(g,e,time+1,p,t,a,node) ) , child = true;
        }
        if (child)
        p[node]+=mx;
        cout<<node<<' '<<p[node]<<endl;
        return p[node];
    }

    int mostProfitablePath(vector<vector<int>>& ed, int b, vector<int>& a) {
        int n = ed.size()+1;
        vector <vector <int>> g (n);
        vector <int> p (n);
        for (auto &e : ed) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        parent (g,0,p,-1);
        vector <int> t (n,2e9);
        int cur = 0;
        while (b !=-1) {
            t[b] = cur++;
            b = p[b];
        }
        vector <int> pr(n);
        return dfs (g,0,0,pr,t,a,-1);
    }
};