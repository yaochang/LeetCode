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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
        	return 0;
        root->val = 1;
        int maxWidth = 1;
        TreeNode* current = NULL;
        std::queue<TreeNode*> queue;
        std::queue<int> queue_pos;
        queue.push(root);
        queue_pos.push(1);

        int count = 1;
        int tmpcount = 0;

        int start = 1; //for the root index
        int end;
        while(!queue.empty()) {
 		   current = queue.front();
 		   queue.pop();
 		   end = queue_pos.front();
 		   queue_pos.pop();

 		   if(current->left != NULL) {
				queue.push(current->left);
				queue_pos.push(end * 2);  //be careful, do not use current->val
				tmpcount++; 		   	
 		   }

 		   if(current->right != NULL) {
 		   		queue.push(current->right);
 		   		queue_pos.push(end * 2 + 1);
 		   		tmpcount++;
 		   }

 		   count--;
 		   if(count == 0) { //if the one level is iterated, then next level
 		   		count = tmpcount;
 		   		tmpcount = 0;
 		   		if(end - start + 1 > maxWidth) {
 		   			maxWidth = end - start + 1;
 		   		}
 		   		if(!queue_pos.empty()) {
 		   			start = queue_pos.front();
 		   		}else{
 		   			start = 1;
 		   		}
 		   }
    	} // end while
    	return maxWidth;
    }
};