class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //move the elements in nums1. To avoid coverage, we need to move the element backwards.
        for(int i=m-1; i>=0; i--) {
        	nums1[i+n] = nums1[i]; 
        }
        int idx1 = n;
        int idx2 = 0;
        for(int i=0; i<m+n; i++) {
        	if(idx1 == m+n) {
        		nums1[i] = nums2[idx2];
        		idx2++;
        		continue;
        	}
        	if(idx2 == n) {
        		return;
        	}
        	if(nums1[idx1] < nums2[idx2]) {
        		nums1[i] = nums1[idx1];
        		idx1++;
        	}else{
        		nums1[i] = nums2[idx2];
        		idx2++;
        	}
        }
        return;
    }
};