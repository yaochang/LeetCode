class Solution {
public:
    int countSegments(string s) {
        int len = s.length();
        if(len == 0)
        	return 0;
        int count = 0;
        int flag = true;
        for(int i=0; i<len; i++) {
        	if(s[i] == ' '){
        		flag = true;
        		continue;
        	}
        	else{
        		if(flag == true) {
        			count++;
        			flag = false;
        		}else{
        			continue;
        		}
        	}
        }
        return count;
    }
};