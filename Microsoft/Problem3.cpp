// Problem Link -: https://leetcode.com/problems/bulls-and-cows/description/

// Solution

class Solution {
public:
    string getHint(string s, string g) {
        int bulls = 0 , cows = 0;
        map <char,int>  m ;
        for (int i=0;i< s.size();i++) {
            if (s[i]==g[i]) bulls ++ , s[i] = '#' , g[i]='#';
            else m[s[i]] ++;
        }
        for (int i=0;i<g.size();i++) {
            if (g[i]=='#') continue;
            if (m[g[i]]) m[g[i]]-- , cows ++;
        }
        string ans  ="";
        ans +=to_string(bulls);
        ans+='A';
        ans+=to_string(cows);
        ans+='B';
        return ans;
    }
};