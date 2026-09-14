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
    void trav(TreeNode* r, vector<int>& ans){
        if(r == NULL){
            ans.push_back(-101); // Null marker => for special case see in notes
            return;
        }
        ans.push_back(r->val);
        trav(r->left, ans);
        trav(r->right, ans);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> ans1;
        vector<int> ans2;
        trav(p, ans1);
        trav(q, ans2);
        return ans1 == ans2;
    }
};