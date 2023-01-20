// Problem Link -: https://leetcode.com/problems/count-nice-pairs-in-an-array/


// Solution 

class Solution {
public:
    int countNicePairs(vector<int>&v) {
        int n = v.size();
        auto rev  = [&] (int num){int ans  = 0; while (num){ans = ans*10 + num%10;num/=10;}return ans;};
        for (int i=0;i<n;i++) v[i] -= rev (v[i]);
        unordered_map <int,long long>  m ;
        m[v[0]] ++;
        long long ans = 0;
        long long mod = 1e9+7;
        for (int i=1;i<n;i++) {
            ans = (ans+ m[v[i]])%mod;
            m[v[i]]++;
        }
        return (int) ans;
    }
};