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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int len = nums.size();
        return constructor(nums, 0, len-1);
    }

    TreeNode* constructor(vector<int>& nums, int start, int end) {
    	if(start > end) {
    		return NULL;
    	}
    	int pivot = INT_MIN;
    	int pivot_idx;
    	for(int i=start; i<=end; i++) {
    		if(nums[i] > pivot) {
    			pivot = nums[i];
    			pivot_idx = i;
    		}
    	}
    	TreeNode* root = new TreeNode(pivot);
    	root->left  = constructor(nums,start,pivot_idx-1);
    	root->right = constructor(nums,pivot_idx+1, end);
    	return root;
    }
};