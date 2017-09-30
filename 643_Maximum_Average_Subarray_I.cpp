/*
 * The naive O(n^2) solution is not suitable.
 */

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len = nums.size();
        double ret = INT_MIN;
        double tmp_sum = 0.0;

        for(int i=0; i<k; i++) {
        	tmp_sum += nums[i];
        }
        ret = tmp_sum;

        for(int i=1; i<len-k+1; i++) {
        	tmp_sum = tmp_sum - nums[i-1] + nums[i+k-1];
        	if(tmp_sum > ret) {
        		ret = tmp_sum;
        	}
        }
        return ret/k;
    }
};