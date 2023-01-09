// Problem Link -: https://leetcode.com/problems/perfect-rectangle/description/

// Solution 

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>&r) {
        set <int> xx  ;
        for  (auto &e : r ) xx.insert(e[0] ) ,xx.insert(e[2] ) ;
        vector <int> x ;
        x.reserve (xx.size()); for  (auto &e : xx) x.push_back(e);
        int id = 0;
        set <int> y ; 
        for  (auto &e : r )y.insert(e[1]), y.insert(e[3]);
        map <int , vector <tuple <int , int , bool>>> m ; 
        for (auto &e : r) {
            auto st = lower_bound (x.begin(),x.end(), e[0])-x.begin();
            auto en = lower_bound (x.begin(), x.end(), e[2])-x.begin();
            m[e[1]].push_back({ st,en-st, false});
            m[e[3]].push_back ({st,en-st, true});
        }
        vector <int> p (x.size());
        while (y.size()) {
            int pos = *y.rbegin();
            y.erase (pos);
            for (auto &e : m[pos]) {
                auto [a,b,c] = e;
                if (c)  {
                    p[a]++;
                    p[a+b]--;
                }
                else {
                    p[a]--;
                    p[a+b]++;
                }
            }
            int sum = 0;
            if (y.size()!=0) {
                for (int i=0;i<p.size()-1;i++) {
                    sum+=p[i];
                    if (sum !=1) return false;
                }
            }
            else {
                for (int i=0;i<p.size()-1;i++) {
                    sum+=p[i];
                    if (sum !=0) return false;
                }
            }
        }
        return true;
    }
};