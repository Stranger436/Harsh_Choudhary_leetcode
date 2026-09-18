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
    TreeNode* solve(vector<int>& inorder, int inst, int inend, vector<int>& postorder, int posst, int posend, map<int, int>& mpp){
        if(inst > inend || posst > posend) return NULL;

        TreeNode* root = new TreeNode(postorder[posend]); // first root
        int inroot = mpp[root->val]; // inorder mai jha root
        int numleft = inroot - inst; // nums on left
        // postorder => left , right, root

        // LEFT sub tree
        root->left = solve(inorder, inst, inroot - 1, postorder, posst, posst + numleft - 1, mpp);
        // RIGHT sub tree
        root->right = solve(inorder, inroot+1, inend, postorder, posst+numleft, posend - 1, mpp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mpp;

        for(int i = 0; i < inorder.size(); i++){
            mpp[inorder[i]] = i;
        }

        TreeNode* root = solve(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mpp);
        return root;
    }
};