// Problem Link -: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

// Solution 


class Solution {
public:
long long mod = 1e9+7;
    long long dfs (vector <vector <pair<int,int>>> &g ,int node , vector <long long> &dp , vector <long long> &d){
        if (dp[node]!=0)  return dp[node];
        long long ans  =  0;
        for (auto &e : g[node]) {
            long long tim = e.second;
            if (d[node]-e.second != d[e.first]) continue;
            if (dp[node])  ans  =  (ans + dp[e.first])%mod;
            else ans = (ans + dfs (g,e.first,dp,d) )%mod;
        }
        dp[node] = ans ;
        return dp[node];
    }

    int countPaths(int n, vector<vector<int>>& r) {
        vector <vector <pair<int,int>>> g (n);
        for (auto &e : r) {
            g[e[0]].push_back({e[1],e[2]});
            g[e[1]].push_back({e[0],e[2]});
        }
        priority_queue <pair <long long ,int> , vector <pair <long long ,int>> , greater <pair<long long,int>>> q;
        q.push({0,n-1});
        vector <long long > d(n,1e18);
        d[n-1] = 0;
        vector <bool> v (n);
        int c = n;
        while (c) {
            auto p = q.top();
            q.pop();
            if (v[p.second]) continue;
            c--;
            v[p.second] = true;
            for (auto &e : g[p.second]) {
                if (d[e.first] > p.first + e.second) {
                    d[e.first] = p.first + e.second ;
                    q.push({d[e.first], e.first});
                }
            }
        }
        vector <long long> dp (n);
        vector <bool> viss (n);
        viss[n-1] = true;
        dp[n-1] = 1;
        return (int)dfs(g,0,dp,d);
    }
};