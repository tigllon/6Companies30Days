// Problem Link -: https://leetcode.com/problems/combination-sum-iii/


// Solution 

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if ( n > 45) return  {};
        vector <vector <int>> ans ;
        auto calc = [&] (int num) {
            int i = 1;
            int sum = 0;
            while (num) {
                if (num&1) sum +=i;
                num >>=1;
                i++;
            }
            return (sum==n);
        };

        auto vec = [&] (int num) {
            vector <int> v ;
            int i = 1;
            while (num) {
                if (num&1) v.push_back(i);
                num >>=1;
                i++;
            }
            return v;
        };
        for (int i = 0; i < (1<<9)  ; i++)  {
            if (__builtin_popcount (i)!=k) continue;
            if (calc(i)) ans.push_back(vec(i));
        }
        return ans ;
    }
};

