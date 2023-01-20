// problerm Link -: https://leetcode.com/problems/count-good-triplets-in-an-array/description/


// Solution 

#include <ext/pb_ds/assoc_container.hpp>                                       
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
class Solution {
public:
    long long goodTriplets(vector<int>& a, vector<int>& b) {
        int n  =a.size();
        vector <int> z (n);
        for (int i=0;i<n;i++) z[a[i]]=i;
        for (int i=0;i<n;i++) b[i] =z[b[i]];
        ordered_set l , r ; 
        for (int i=1;i<n;i++) r.insert(b[i]);
        l.insert(b[0]);
        long long ans  = 0;
        for (int i=1;i<n-1;i++) {
            r.erase(b[i]);
            long long left  = l.order_of_key(b[i]);
            long long right = r.size()-r.order_of_key(b[i]);
            l.insert(b[i]);
            ans +=left*right;
        }
        return ans ; 
    }
};