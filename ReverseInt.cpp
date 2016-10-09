class Solution {
public:
    /*
     * How to handle the overflow is the most important part!
     */
    int reverse(int x) {   
	int f = 1;
	long long copy_x = (long long)x;
	if(copy_x < 0){
		f = -1;
		copy_x = abs(copy_x);
	}
	if(copy_x < 10) return f*copy_x;
	long long base = 1;
	long long number = copy_x;
	while(number >= 10) {
		number = number/10;
		base = base * 10;
	}
	number = copy_x;
	int bit;
	long long ret = 0;
	while(number > 0) {
		bit = number % 10;
		number = number / 10;
		ret = ret + bit * base;
		base = base / 10; 
	}
	ret = ret * f;
	if(ret > INT_MAX || ret < INT_MIN) return 0;
	else return ret;
    }
};
