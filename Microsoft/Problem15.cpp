// Problem Link -: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/



// Solution 
class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = -1 , b = -1 , c = -1;
        int ans =0;
        for (int i=0;i<s.size();i++) {
            if (s[i]=='a') a = i;
            if (s[i]=='b') b = i;
            if (s[i]=='c') c = i;
            if (a !=-1 && b!=-1 && c!=-1)  ans +=min ({a,b,c})+1;
        }
        return ans;
    }
};