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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mpp;

        for(int i = 0; i < inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        TreeNode* root = solve(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mpp);
        return root;
    }
    TreeNode* solve(vector<int>& preorder, int prest, int preend, vector<int>& inorder, int inst,
    int inend, map<int, int>& mpp){
        if(inst > inend || prest > preend) return NULL; // no one needs to backtarck

        TreeNode* root = new TreeNode(preorder[prest]);

        int inroot = mpp[root->val];
        int numLeft = inroot - inst;

        root->left = solve(preorder, prest+1, prest+numLeft, inorder, inst, inroot-1, mpp);
        root->right = solve(preorder, prest+numLeft+1, preend, inorder, inroot+1, inend, mpp); 

        return root;
    }
};