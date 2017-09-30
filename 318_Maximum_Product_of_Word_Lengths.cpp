class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        if(len == 0) {
        	return 0;
        }
        int* flag = new int[len];
        string word;
        int bitpos;
        for(int i=0; i<len; i++) {
        	word = words[i];
        	flag[i] = 0;
        	for(int j=0; j<word.length(); j++) {
        		bitpos = int(word[j]-'a');
        		flag[i] = flag[i] | (1 << bitpos); //make use of bit operation to compute common letters
        	}
        }

        int ret = 0;
        int tmpret;
        for(int i=0; i<len; i++) {
        	for(int j=i+1; j<len; j++) {
        		if((flag[i] & flag[j]) == 0) { //not share the common letters
        			tmpret = words[i].length() * words[j].length();
        			if(tmpret > ret) {
        				ret = tmpret;
        			}
        		}
        	}
        }
        return ret;
    }
};