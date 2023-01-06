// Problem Link -: https://leetcode.com/problems/number-of-pairs-satisfying-inequality/description/

//Solution 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define multi_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    long long numberOfPairs(vector<int>& a, vector<int>& b, int diff) {
        int n = a.size();
        for (int i=0;i<n;i++) a[i]-=b[i];
        multi_set  m ;
        for (int i=1;i<=n;i++) m.insert ({a[i-1],i});
        long long  ans  = 0;
        for (int i=0;i<n-1;i++) {
            m.erase (m.find_by_order(m.order_of_key({a[i],i+1})));
            int ind = m.order_of_key ({a[i]-diff,-1});
            ans += ((long long )m.size()-ind);
        }
        return ans;
    }
};

