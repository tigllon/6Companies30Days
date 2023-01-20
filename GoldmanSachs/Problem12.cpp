// Problem Link -: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/


// Solution 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector <int> ans;
        stack <pair <TreeNode *,int>> a, b;
        if (root1!=NULL)
        a.push({root1,0});
        if (root2!=NULL)
        b.push({root2,0});
        auto val = [&] () {
            while (a.size() && a.top().second==2)a.pop();
            while (b.size() && b.top().second==2)b.pop();
            return true;
        };
        while (val() && a.size() && b.size()) {
            while (a.top().second !=1)  {
                auto p = a.top();
                a.pop();
                p.second = 1;
                a.push(p);
                if (a.top().first->left !=NULL) a.push({a.top().first->left , 0});
            }
            while (b.top().second !=1)  {
                auto p = b.top();
                b.pop();
                p.second = 1;
                b.push(p);
                if (b.top().first->left !=NULL) b.push({b.top().first->left , 0});
            }
            if (a.top().first->val <=b.top().first->val) {
                ans.push_back(a.top().first->val);
                auto p = a.top();
                a.pop();
                p.second=2;
                a.push (p);
                if (a.top().first->right !=NULL) a.push ({a.top().first->right , 0});
            }
            else {
                ans.push_back(b.top().first->val);
                auto p = b.top();
                b.pop();
                p.second=2;
                b.push (p);
                if (b.top().first->right !=NULL) b.push ({b.top().first->right , 0});
            }
        }

        while (a.size()) {
            if (a.top().second==0) {
                auto p = a.top();
                a.pop();
                p.second = 1;
                a.push(p);
                if (a.top().first->left !=NULL) a.push({a.top().first->left , 0});
            }
            else if (a.top().second==1) {
                ans.push_back(a.top().first->val);
                auto p = a.top();
                a.pop();
                p.second = 2;
                a.push(p);
                if (a.top().first->right !=NULL) a.push({a.top().first->right , 0});
            }
            else a.pop();
        }


        while (b.size()) {
            if (b.top().second==0) {
                auto p = b.top();
                b.pop();
                p.second = 1;
                b.push(p);
                if (b.top().first->left !=NULL) b.push({b.top().first->left , 0});
            }
            else if (b.top().second==1) {
                ans.push_back(b.top().first->val);
                auto p = b.top();
                b.pop();
                p.second = 2;
                b.push(p);
                if (b.top().first->right !=NULL) b.push({b.top().first->right , 0});
            }
            else b.pop();
        }
        return ans;
    }
};