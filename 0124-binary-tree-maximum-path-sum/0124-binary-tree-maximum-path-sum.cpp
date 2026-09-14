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
    int dfs(TreeNode* root, int& maxi){
        if(root == NULL) return 0;

        int leftsum = dfs(root->left, maxi);
        int rightsum = dfs(root->right, maxi);

        // Ignore negative paths
        leftsum = max(0, leftsum);
        rightsum = max(0, rightsum);

        maxi = max(maxi, leftsum + rightsum + root->val);

        return root->val + max(leftsum, rightsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        dfs(root, maxi);
        return maxi;
    }
};