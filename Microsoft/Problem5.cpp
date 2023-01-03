// Problem Link -: https://leetcode.com/problems/largest-divisible-subset/description/

// Solution 

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& v) {
        int n = v.size();
        sort (v.begin() , v.end());
        vector <int> mx(n,1)  ; 
        vector <int> p (n , -1);
        for (int i=1;i<n;i++) {
            for (int j=i-1;j>=0;j--) {
                if (v[i]%v[j]!=0 ) continue;
                if (mx[i] < mx[j]+1) {
                    mx[i] = mx[j]+1;
                    p[i]  =j;
                }
            }
        }
        auto ind = max_element (mx.begin(),mx.end())-mx.begin();
        vector <int> ans ;
        while (ind!=-1) {
            ans.push_back(v[ind]);
            ind = p[ind];
        }
        reverse(ans.begin() ,ans.end());
        return ans;
    }
};