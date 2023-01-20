// Problem Link -: https://leetcode.com/problems/maximum-points-in-an-archery-competition/description/


// Solution

class Solution {
public:
    vector<int> maximumBobPoints(int t, vector<int>& w) {
        int n  =w.size();
        int anss  = 0;
        int value = 0;
        for (int i=0;i<(1<<n);i++) {
            int sum = 0;
            int v = i;
            int ind = 0;
            int p = 0;
            while (v) {
                if (v&1) sum+=(w[ind]+1) , p+=ind;
                ind ++;
                v>>=1;
            }
            if (sum >t) continue;
            if (anss < p) {
                anss   =p;
                value = i;
            }
        }
        vector <int> ans(n,0); 
        int ind = 0;
        int sum  =0;
        while (value) {
            if (value&1) ans[ind] = (w[ind]+1), sum+=(w[ind]+1);
            else ans[ind] = 0;
            ind ++;
            value>>=1;
        }
        if (sum < t) ans.back()+=(t-sum);
        return ans;
    }
};