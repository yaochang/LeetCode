/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        int cnt = intervals.size();
        if(cnt == 0)
        	return ret;
        sort(intervals.begin(), intervals.end(), cmp);
        Interval tmp = intervals[0];
        for(int i=1; i<cnt; i++) {
    		if(tmp.end >= intervals[i].start) {
    			tmp.end = max(tmp.end, intervals[i].end);
    		}else{
    			ret.push_back(tmp);
    			tmp = intervals[i];
    		}
        }
        ret.push_back(tmp);
        return ret;
    }

    int max(int a, int b) {
    	if(a > b) return a;
    	else return b;
    }

    static bool cmp(Interval& a, Interval& b) {
    	if(a.start < b.start) {
    		return true;
    	}else if(a.start > b.start) {
    		return false;
    	}else{
    		return a.end < b.end;
    	}
    }
};