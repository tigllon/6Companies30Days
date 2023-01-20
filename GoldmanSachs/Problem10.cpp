// Problem Link -: https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/

// Solution 

class Solution {
public:
    int peopleAwareOfSecret(int n, int D, int F) {
        long long mod =1e9+7;
        vector <long long> v (n+1);
        vector <long long> sum (n+1);
        v[1] = 1;
        sum[1] = 1;
        for (int i=2;i<=n;i++) {
            int dend = max (0,i-D);
            int fend = max (0,i-F);
            v[i] = (v[i]+ sum[dend]-sum[fend]+10*mod)%mod;
            sum[i] = (sum[i-1] + v[i])%mod;
        }
        long long ans  = 0;
        for (int i=n;i>max (n-F,0);i--) ans = (ans + v[i])%mod;
        return (int) ans;
    }
};