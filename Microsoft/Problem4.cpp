// Problem Link -: https://leetcode.com/problems/rotate-function/description/


// Solution


class Solution {
public:
    int maxRotateFunction(vector<int>& v) {
        long long  sum = 0;
        for (auto &e : v) sum+=e;
        long long  c_sum = 0;
        for (int i=0;i<v.size();i++) c_sum+=i*v[i];
        long long ans  = c_sum;
        for (int i=(int)v.size()-2;i>=0;i--) {
            long long  t = sum+c_sum-v[i+1]*(int)v.size();
            ans  = max (ans ,t);
            c_sum = t;
        }
        return (int) ans ;
    }
};

