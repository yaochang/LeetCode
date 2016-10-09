class Solution {
public:
    	bool isPalindrome(int x) {
		long long copy_x = (long long)x;
		if(copy_x < 0) return false; //if the number is less than 0, return false

		long long bit_cnt = 1;  
		if(copy_x < 10) return true;	// if the number is smaller than 10, return true

		long long cur_x = copy_x;
		while(cur_x >= 10){
			bit_cnt++;
			cur_x = cur_x / 10;
		}

		int left=bit_cnt;
		int right=1;
		int l_bit;
		int r_bit;
		while(left >= right) {
			r_bit = getKth(copy_x, right);
			l_bit = getKth(copy_x, left);
			if(r_bit != l_bit) return false;
			left--;
			right++;
		}
		return true;
    	}
	

	/*
	 * Get the Kth bit in number x from the right side
	 * With this function, the comparison becomes much easier
	 */
    	int getKth(long long x, int k) {
	  	long long cur_x = x;
		while(k>1){
			cur_x = cur_x / 10;
			k = k - 1;
		}
		return cur_x % 10;
	}
};
