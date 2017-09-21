class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if(len == 0) 
            return 0;
        return search(height, 0, len-1);
    }
    
    int search(vector<int>&height, int idx, int max_idx) {
        if(idx >= max_idx || idx < 0)
            return 0;

        int cnt = 0;                    //total area
        int ret = 0;                    //rain water area
        int c_height = height[idx];
        int sub = c_height;             //subtract area

        int tmp_max_height = 0;         //to record the max right bar heigth
        int tmp_max_idx = -1;           //to recrod the max right bar index
        int tmp_sub = 0;              

        int i = 0;
        for(i=idx+1; i<=max_idx; i++) {
        	if(c_height > height[i]) {   
        		sub += height[i];
                if(height[i] > tmp_max_height) { 
                    tmp_max_idx = i;
                    tmp_max_height = height[i];
                    tmp_sub = sub - c_height;
                }
        	}else{     //if the bar is higher than the start bar, calculate the area
        		sub = sub + c_height;
        		cnt = c_height * (i - idx + 1) - sub;
                return  cnt + search(height, i, max_idx); //continue from the higher bar
        	}
        } 

        //if all the right bar is lower than the starting bar
        cnt = tmp_max_height * (tmp_max_idx - idx +1) - tmp_sub - tmp_max_height;
        ret = cnt + search(height, tmp_max_idx, max_idx);

        return ret;
    }
};