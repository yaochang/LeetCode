/*
 * flowers[day] = position
 * ==> days[poistion] = day
 *
 * find a subarray,[left, right], for any left < i < right ==> days[i]>days[left] && days[i]>days[right]
 */




class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
    	int len = flowers.size();
    	vector<int> days(len);
    	for(int i=0; i<len; i++) {
    		days[flowers[i]-1] = i+1;
    	}
    	int left=0, right=k+1, ret=INT_MAX;
    	for(int i=0; right<len; i++) {
    		if(i == right) {
    			ret = min(ret, max(days[left], days[right]));
    		}
    		if(days[i] < days[left] || days[i] < days[right]) { 
    			//this is not a correct answer
    			left = i;
    			right = i + k + 1;
    		}
    	}

    	if(ret == INT_MAX) //only when we found a correct answer, the ret is not INT_MAX
    		return -1;
    	else
    		return ret;
    }
};