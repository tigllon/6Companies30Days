// Problem Link -: https://leetcode.com/problems/longest-happy-prefix/description/


// Solution 

class Solution {
public:
    string longestPrefix(string s) {
        int n  =s.size();
        vector <int> v (n);
        v[0]=0;
        for (int i=1;i<n;i++) {
            if (s[v[i-1]]==s[i]) v[i]=v[i-1]+1;
            else {
                int j = v[i-1];
                while (j > 0 && s[j] !=s[i])  j = v[j-1];
                if (s[j]==s[i])v[i] = j+1;
                else v[i] = 0;
            }
        }
        return s.substr (0,v.back());
    }
};

