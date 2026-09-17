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
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target) {
        queue<TreeNode*> queue; // will do a level order tarversal 
        queue.push(root);
        while(!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            if(current->left) {
                parent_track[current->left] = current; // curr ke left ka parent curr itself
                queue.push(current->left);
            }
            if(current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;  // node -> parent {store every node's parent}
        markParents(root, parent_track, target);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> queu;
        queu.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!queu.empty()){ // Second bfs to go upto k level and using our hashtable
            int size = queu.size();
            if(curr_level++ == k) break;
            for(int i = 0; i < size; i++){
                TreeNode* current = queu.front();
                queu.pop();
                if(current->left && !visited[current->left]){ // if unvisited left h current ka 
                    queu.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]){
                    queu.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]){ // parent exist and not visited
                    queu.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> result;
        while(!queu.empty()){
            TreeNode* curr = queu.front();
            queu.pop();
            result.push_back(curr->val);
        }
        return result;
    }
};