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
    int sumNumbers(TreeNode* root) {
    	if(root == NULL) {
    		return 0;
    	}    
    	if(root->val == 0) {
    		return sumNumbers(root->left) + sumNumbers(root->right);
    	}
    	if(root->left == NULL && root->right == NULL) {
    		return root->val;
    	}

    	int sum = 0;
    	if(root->left != NULL) {
    		root->left->val = 10 * root->val + root->left->val;
    		sum = sum + sumNumbers(root->left);
    	}
    	if(root->right != NULL) {
    		root->right->val = 10 * root->val + root->right->val;
    		sum = sum + sumNumbers(root->right);
    	}
    	return sum;
    }

};