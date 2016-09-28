class Solution {
public:
	double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
	  	int len1 = num1.size();
		int len2 = num2.size();
		int len = len1 + len2;
		int k1, k2;
		int ret1, ret2;
		double ret;
		if(len%2 == 1) {
			k1 = len/2 + 1; 
			ret1 =	findKthNumber(num1, 0, len1-1, num2, 0, len2-1, k1);
		 	ret2 = ret1;
			ret = ((double)ret1 + (double)ret2) / 2;
		}else{
			k1 = len/2;
			k2 = len/2 + 1;
			ret1 = findKthNumber(num1, 0, len1-1, num2, 0, len2-1, k1);
			ret2 = findKthNumber(num1, 0, len1-1, num2, 0, len2-1, k2);
			ret = ((double)ret1 + (double)ret2)/ 2;
		}
		return ret;
    	}
    
    	int min(int a, int b) {
        	if(a < b) return a;
        	else return b;
    	}	
    	
	/*
	 * The most important part is the boundary bugs.
	 * both pa and pb should be bounded by min(k/2, len)
 	 */
	int findKthNumber(vector<int>& num1, int s1, int e1, vector<int>& num2, int s2, int e2, int K) {
		int len1 = e1 - s1 + 1;
		int len2 = e2 - s2 + 1;
		if(len2 > len1) return findKthNumber(num2, s2, e2, num1, s1, e1, K);
		if(len2 <= 0) return num1[s1+K-1];
		if(K == 1) {
		    return min(num1[s1], num2[s2]);
		}
		
		int pa = min(K/2, len1-1);
		int pb = min(K/2, len2-1);
		if(num1[s1+pa-1] < num2[s2+pb-1]) {
			return findKthNumber(num1, s1+pa, e1, num2, s2, e2, K - pa);
		}else{
			return findKthNumber(num1, s1, e1, num2, s2+pb, e2, K - pb);
		}
	}
	
};
