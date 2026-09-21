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
// class Solution {
// public:
//     void dfs(TreeNode* root, int k, int &cnt, int &ans) {
//         if(root == NULL) return;
//         // Left
//         dfs(root->left, k, cnt, ans);
//         // Node
//         cnt++;
//         if(cnt == k) {
//             ans = root->val;
//             return;
//         }
//         // Right
//         dfs(root->right, k, cnt, ans);
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         int cnt = 0;
//         int ans = -1;
//         dfs(root, k, cnt, ans);
//         return ans;
//     }
// };

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur = root;
        int ans = -1;
        while(cur != NULL) {
            // No left subtree
            if(cur->left == NULL) {
                k--;
                if(k == 0){
                    ans = cur->val;
                }
                cur = cur->right;
            }
            // Left subtree exists
            else {
                TreeNode* prev = cur->left;
                // Find inorder predecessor
                while(prev->right != NULL && prev->right != cur) {
                    prev = prev->right;
                }
                // Create thread
                if(prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left;
                }
                // Remove thread (when again visited)
                else {
                    prev->right = NULL;
                    k--;
                    if(k == 0){
                        ans = cur->val;
                    }
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};