/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        int cur = root->val;
        // if both is on right go right
        if(cur < p->val && cur < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        // if both is in left go left
        if(cur > p->val && cur > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        return root; // when we cannot say that both are on left or on right side
    }
};