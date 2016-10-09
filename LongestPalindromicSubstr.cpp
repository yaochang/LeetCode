class Solution {
public:
    	string longestPalindrome(string s){
		int size = s.length();
		if(size <= 1) return s;
		int tag[1001][1001];
		memset(tag, 0, sizeof(tag));
		for(int i=0; i<size-1; i++){
			tag[i][i] = 1;
			if(s[i] == s[i+1]) {
			    tag[i][i+1] = 1;
			    tag[i+1][i] = 1;
			}
		}
		tag[size-1][size-1] = 1;
		int left=0;
		int maxl = 1;
		for(int l=2; l<=size; l++) { //string length
			for(int b=0; b<=size-l; b++) { //start position
				if(s[b] == s[b+l-1] && tag[b+1][b+l-2] == 1) {
					tag[b][b+l-1] = 1;
					if(l >= maxl) {
						maxl = l;
						left = b;
					}
				}
			}
		}
		return s.substr(left, maxl);
	}
	
};
