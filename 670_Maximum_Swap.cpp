class Solution {
public:
    int maximumSwap(int num) {
  		if(num == 0)
  			return 0;
  		vector<int> digits;
  		int digit;
  		int idx=0;
  		int num_tmp = num;
  		while(num_tmp > 0) {
  			digit = num_tmp % 10;
  			digits.push_back(digit);
  			num_tmp = num_tmp / 10;
  			idx++;
  		}
  		bool tag = false;
  		int tmpmax = 0;
  		int tmpidx = 0;
  		for(int i=idx-1; i>=0; i--) {
  			tmpmax = 0;
  			for(int j=i-1; j>=0; j--) { 
  				/*
				 * ">=" guarantee to change the smaller digit
				 * for example: 1993 --> 9913 instead of 9193
  				 */
  				if(digits[j] > digits[i] && digits[j] >= tmpmax) {  
  					tmpmax = digits[j];
  					tag = true;
  					tmpidx = j;
  				}
  			}
  			if(tag == true) {   //swap the digits once
  				num_tmp = digits[i];
  				digits[i] =  digits[tmpidx];
  				digits[tmpidx] = num_tmp;
  				break;
  			}
  		}

  		if(tag == false) return num; // if there is no swap happen, return original input number
  		num_tmp = 0;
  		for(int i=idx-1; i>=0; i--) {
  			num_tmp = num_tmp * 10 + digits[i];
  		}
  		return num_tmp;

    }
};