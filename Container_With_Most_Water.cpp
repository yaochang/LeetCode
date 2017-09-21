class Solution {
public:
    int maxArea(vector<int>& height) {
  		int len = height.size();
  		if(len < 2)
  			return 0;
        int ret = 0;
  		int left  = 0;
  		int right = len - 1;
  		while(left < right) {
  			ret = max(ret, min(height[left], height[right]) * (right - left));
  			if(height[left] < height[right])
  				left++;
  			else
  				right--;
  		}
  		return ret;     
    }

    int max(int a, int b) {
        if(a>b) return a;
        else return b;
    }
    
    int min(int a, int b) {
        if(a<b) return a;
        else return b;
    }
};