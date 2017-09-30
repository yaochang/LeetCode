class Solution {
public:
	/*
     * sort the pair array according a ascending order of the second element
	 */
    int findLongestChain(vector<vector<int>>& pairs) {
        //sort the pairs according the second element
        int len = pairs.size();
        if(len == 0) {
        	return 0;
        }
        sort(pairs.begin(), pairs.end(), cmp);
        vector<int> c_pair(2);
        int cnt = 0;
        for(int i=0; i<len; i++) {
        	if(i == 0 || c_pair[1] < pairs[i][0]) {
        		cnt++;
        		c_pair = pairs[i];
        	}
        }
        return cnt;
    }

    /*
     * solution use DP alogirthm which sort the array according a ascending order of the first element
     */
    int findLongestChain(vector<vector<int>>& pairs) { 
    	int len = pairs.size();
    	if(len == 0) {
    		return 0;
    	}
    	sort(pairs.begin(), pairs.end(), cmp);
    	int* dp = new int[len];
    	for(int i=0; i<len; i++) {
    		dp[i] = 1;
    	}
    	int ret = 0;
    	for(int i=0; i<len; i++) {
    		for(int j=0; j<i; j++) {
    			if(pairs[j][1] < pairs[i][0]) {
    				dp[i] = max(dp[i], dp[j] + 1);
    			}
    		}
    		if(dp[i] > ret) {
    			ret = dp[i];
    		}
    	}
    	return ret;
    }

    static bool cmp(vector<int>& a, vector<int>&b) {
        return a[1] < b[1];
    }

    int max(int a, int b) {
    	if(a > b) return a;
    	else return b;
    }
};