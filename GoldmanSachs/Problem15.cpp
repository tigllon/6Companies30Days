// Problem Link -: https://leetcode.com/problems/maximum-good-people-based-on-statements/description/


// Solution 

class Solution {
public:
    int maximumGood(vector<vector<int>>&v) {
        int n  =v.size();
        auto validate  = [&] (int a) {
            vector <int> p (n);
            int ind = 0;
            while (a) {
                if (a&1) p[ind]++;
                a>>=1;
                ind ++;
            }
            for (int j = 0; j< n ; j++) {
                bool bad =false;
                if (p[j]==0) bad = true;
                for (int i=0;i<n;i++) {
                    if (v[i][j]==2) continue;
                    if (bad) {
                        if (v[i][j]==1 && p[i]==1) return false;
                    }
                    else {
                        if (v[i][j]==0 && p[i]==1) return false;
                    }
                }
            }
            cout<<"dsl;mss"<<endl;
            return true;
        };
        int ans  = 0;
        for (int i = 0; i< (1<<n) ; i++) {
            if (validate (i)) ans  =max (ans , __builtin_popcount (i)) ;
        }
        return ans;
    }
};