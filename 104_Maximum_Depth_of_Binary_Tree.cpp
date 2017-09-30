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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
        	return 0;
        root->val = 1;
        queue<TreeNode*> que;
        que.push(root);
        int max_depth = 0;
        TreeNode* current;
        while(!que.empty()) {
        	current = que.front();
        	que.pop();
        	if(current->val > max_depth) {
        		max_depth = current->val;
        	}
        	if(current->left != NULL) {
        		current->left->val = current->val + 1;
        		que.push(current->left);
        	}
        	if(current->right != NULL) {
        		current->right->val = current->val + 1;
        		que.push(current->right);
        	}
        }
        return max_depth;
    }

};