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
    TreeNode* deleteNode(TreeNode* root, int key) {
    	if(root == NULL) return root;
    	TreeNode* removeNode = NULL;
    	TreeNode* ret = NULL;
    	if(root->val == key) {  /*add a temporal root to handle root case*/
    		TreeNode* tmpRoot = new TreeNode(key+1);
    		tmpRoot->left = root;
    		removeNode = remove(root, key, tmpRoot);
    		if(removeNode != NULL) {
    			delete removeNode;
    		}
    		ret = tmpRoot->left;
    	}else{
    		removeNode = remove(root, key, NULL);
    		if(removeNode != NULL) {
    			delete removeNode;
    		}
    		ret = root;
    	}
    	return ret;
    }

    TreeNode* remove(TreeNode* current, int key, TreeNode* parent) {
    	TreeNode* leftnode 	= current->left;
    	TreeNode* rightnode	= current->right;
    	if(current->val < key) { /*the key in the right side*/
    		if(rightnode != NULL) {
    			return remove(rightnode, key, current);
    		}else{
    			return NULL;
    		}	
    	}else if(current->val > key) { /*the key in the left side*/
    		if(leftnode != NULL) {
    			return remove(leftnode, key, current);
    		}else{
    			return NULL;
    		}
    	}else{ /*the key is the current node*/
    		if(leftnode != NULL && rightnode != NULL) { /*if the key node has two children*/
    			current->val = minValue(rightnode);
    			return remove(rightnode, current->val, current);
    		}else if(parent->left == current) { /*if the node is the left child of its parent*/
    			parent->left = (leftnode != NULL) ? leftnode: rightnode;
    			return current;
    		}else if(parent->right == current) {
    			parent->right = (leftnode != NULL) ? leftnode: rightnode;
    			return current;
    		}
    	}
    } // end of remove function

    int minValue(TreeNode* root) {
    	if(root->left == NULL)
    		return root->val;
    	else
    		return minValue(root->left);
    }
};