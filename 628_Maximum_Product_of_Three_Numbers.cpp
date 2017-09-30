class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end(), cmp);
        int ret = nums[0] * nums[1] * nums[2];
        if(nums[0] <= 0) {
        	return ret;
        }
        int tmp = nums[0] * nums[len-1] * nums[len-2];
        if(ret < tmp) {
        	ret = tmp;
        }
        return ret;
    }

    static bool cmp(int& a, int& b) {
    	return a>b;
    }
};