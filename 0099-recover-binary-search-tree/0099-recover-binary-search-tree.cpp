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
private:
    TreeNode* first;
    TreeNode* last;
    TreeNode* mid;
    TreeNode* prev;
private:
    void inorder(TreeNode* root) {
        if(root == NULL) return;
        inorder(root->left);
        // MAIN LOGIC
        if(prev != NULL && root->val < prev->val){
            // if this is first voilation mark these two nodes as, 'first' and 'middle'
            if(first == NULL){
                first = prev;
                mid = root;
            }
            else{ // if this is second , then mark this node as last
                last = root;
            }
        }
        // mark this node as previous
        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = last = mid = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && mid) swap(first->val, mid->val);
    }
};