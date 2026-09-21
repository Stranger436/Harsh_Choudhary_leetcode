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
    void dfs(TreeNode* root, int k, int &cnt, int &ans) {
        if(root == NULL) return;
        // Left
        dfs(root->left, k, cnt, ans);
        // Node
        cnt++;
        if(cnt == k) {
            ans = root->val;
            return;
        }
        // Right
        dfs(root->right, k, cnt, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ans = -1;
        dfs(root, k, cnt, ans);
        return ans;
    }
};