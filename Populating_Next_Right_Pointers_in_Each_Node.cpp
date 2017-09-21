/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        std::queue<TreeLinkNode*> queue;
        int count = 1;
        int tmpcount = 0;
        TreeLinkNode* current = NULL;

        queue.push(root);
        while(!queue.empty()) {
        	current = queue.front();
        	queue.pop();

        	if(current->left != NULL) {
        		queue.push(current->left);
        		tmpcount++;
        	}
        	if(current->right != NULL) {
        		queue.push(current->right);
        		tmpcount++;
        	}
        	count--;
        	if(count == 0) {
        		current->next = NULL;
        		count = tmpcount;
        		tmpcount = 0;
        	}else{
        		current->next = queue.front();
        	}
        }
        return;
    }
};