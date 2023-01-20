// Problem Link -: https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/description/

// Solution 

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& v) {
        int r = v.size() , c = v[0].size();
        vector <vector <int>> l(r+2 , vector <int> (c+2)) , R(r+2 , vector <int> (c+2));
        for (int i=1;i<=r;i++) {
            int x = i;
            for (int j=1;j<=c && x <=r;j++,x++) R[x][j] = R[x-1][j-1] + v[x-1][j-1];
        }
        for (int j=2;j<=c;j++) {
            int y = j;
            for (int i=1;i<=r && y <=c;i++,y++) R[i][y] = R[i-1][y-1]+v[i-1][y-1];
        }
        for (int i=1;i<=r;i++) {
            int x = i;
            for (int j=c;j>0 && x <=r;j--,x++) l[x][j] = l[x-1][j+1] + v[x-1][j-1];
        }
        for (int j=c-1;j>0;j--) {
            int y = j;
            for (int i=1;i<=r && y>0; i++,y--) l[i][y] = l[i-1][y+1]+v[i-1][y-1];
        }
        set <int> ans;
        for (int i=1;i<=r;i++) {
            for (int j=1;j<=c;j++) {
                ans.insert(v[i-1][j-1]);
                for (int k=1;j-k >0 && i+2*k<=r && j+k<=c; k++) {
                    int sum = l[i+k][j-k]- l[i-1][j+1];
                    sum+= (-R[i+k][j-k] + R[i+2*k][j]);
                    sum+= (-l[i+k-1][j+k+1] + l[i+2*k-1][j+1]);
                    sum+= (R[i+k-1][j+k-1] - R[i][j]);
                    ans.insert(sum);
                }
            }
        }
        int co= 3;
        vector <int> fans ; 
        while (ans.size() && co--) fans.push_back(*ans.rbegin()), ans.erase(*ans.rbegin());
        return fans ; 
    }
};