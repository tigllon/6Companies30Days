// Problem Link -: https://leetcode.com/problems/invalid-transactions/description/

// Solution 

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& t) {
        int n  =t.size();
        vector <vector <string>> v;
        vector <string> ans  ;
        for (auto &e : t) {
            stringstream ss (e);
            string s ; 
            vector <string> t ; 
            while (ss.good()) {
                getline (ss,s,',');
                t.push_back(s);
            }
            v.push_back(t);
        }
        auto cmp = [&] (const vector <string> &a , const vector <string> &b ){
            return stoi(a[1]) <stoi(b[1]);
        };
        auto str = [&] (const vector <string> &a) {
            string s  = "";
            for (auto &e : a) s+=e, s+=',';
            s.pop_back();
            ans.push_back(s);
        };
        sort (v.begin(), v.end(), cmp);
        int l = 0 , r = 0;
        unordered_map <string , unordered_map <string , int>> m  ;
        for (int i=0;i<n;i++) {
            while (l <=r && stoi(v[l][1]) +60 < stoi(v[i][1]) ) {
                m[v[l][0]][v[l][3]]--;
                if (m[v[l][0]][v[l][3]]==0) m[v[l][0]].erase(v[l][3]);
                l ++;
            }
            while (r < n && stoi(v[r][1]) -60 <= stoi(v[i][1])) {
                m[v[r][0]][v[r][3]]++;
                r++;
            }
            if(m.count(v[i][0])&&(int)m[v[i][0]].size()-m[v[i][0]].count(v[i][3])>0)str(v[i]);
            else if (stoi(v[i][2])> 1000) str(v[i]);
        }
        return ans;
    }
};