/*
 * Two get the minimum number, one dress cannot be delivered back
 * Thus, for each node, we calculate the number of pass time.
 */

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        if(n == 0 || n == 1) return 0;



        int ret = 0;
        int total = 0; 		//calcuate all total dresses
        int target = 0; 	//calcuate the average dresses in each machine
        int expect = 0;

        int* left  = new int[n];  //not include itself
        int* right = new int[n];
        memset(left,  0, sizeof(left));
        memset(right, 0, sizeof(right));

        for(int i = 0; i < n; i++) {
        	total += machines[i];
        	left[i]  = total - machines[i];
        }

        if(total % n != 0) {  //no matter how to move, the dresses in each machine cannot be equal
        	return -1;
        }
        
        for(int i = 0; i < n; i++) {
        	right[i] = total - left[i] - machines[i];
        }

        target = total / n;
        
        int i_left  = 0;
        int i_right = 0;
        for(int i=0; i < n; i++) {
        	expect  = target * i;  //left
        	i_left  = max(0, expect - left[i]);
        	expect  = target * (n - i - 1);
        	i_right = max(0, expect - right[i]);
        	ret = max(ret, i_left + i_right);
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