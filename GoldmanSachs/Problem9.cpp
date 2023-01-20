// Problem Link -: https://leetcode.com/problems/ipo/description/


// Solution

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& p, vector<int>& c) {
        int n =c.size();
        vector <pair <int,int>> v (n);
        for (int i=0;i<n;i++) v[i] = {c[i],i};
        sort (v.begin(), v.end());
        priority_queue < int > q ;
        int i = -1;
        int w = W;
        while (k--) {
            while (i+1 < n && v[i+1].first <=w) {
                q.push(p[v[i+1].second]);
                i++;
            }
            if (q.size()==0) break;
            else w+=q.top(), q.pop();
        }
        return w;
    }
};