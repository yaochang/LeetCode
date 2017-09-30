class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int cnt = nums.size();
        vector<vector<int> > retset = {{}};    	//initially, put the [] in the return set
        sort(nums.begin(), nums.end());			//sort the vector according to ascending order
        int dcount = 0;							//record the number of duplicate number
        for(int i=0; i<cnt;) {
            dcount = 0;
        	while(i+dcount<cnt && nums[i]==nums[i+dcount]) {  //add one for itself
        		dcount++;
        	}
        	int retcnt = retset.size();
        	for(int j=0; j<retcnt; j++) {					  //iterate all smaller subsets
        		vector<int> v = retset[j];
        		for(int k=0; k<dcount; k++) {				  //put [1, dcount] elements in each subset
        			v.push_back(nums[i]);
        			retset.push_back(v);
        		}
        	}
        	i = i + dcount;									 //handle next element	
        }
        return retset;
    }
};