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
class BSTiterator {
public:
    stack<TreeNode*> st;
    bool reverse;

    BSTiterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    bool hasnext() {
        return !st.empty();
    }

    int next() {
        TreeNode* tmpnode = st.top();
        st.pop();
        if(reverse){
            pushAll(tmpnode->left);
        }
        else{
            pushAll(tmpnode->right);
        }
        return tmpnode->val;
    }

    void pushAll(TreeNode* node) {
        while(node != NULL) {
            st.push(node);
            if(reverse){
                node = node->right;
            }   
            else{
                node = node->left;
            } 
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        BSTiterator l(root, false);  // smallest → largest
        BSTiterator r(root, true);   // largest → smallest

        int i = l.next();
        int j = r.next();
        while(i < j) {
            if(i + j == k){
                return true;
            } 
            else if(i + j < k){
                i = l.next();
            }   
            else{
                j = r.next();
            }     
        }
        return false;
    }
};