/**
 * Dead(0), Live(0)
 * use two bits to indicates two states. 
 * (second state, first state)
 * dead -> dead  00
 * live -> dead  01
 * dead -> live  10
 * live -> live  11  
 * to get current state:  & 1
 * to get next state:	 >> 1
 */


class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int live_cnt = 0;
        for(int i=0; i<m; i++) {
        	for(int j=0; j<n; j++) {
        		live_cnt = liveNeighborCount(board, m, n, i, j);
        		//iniitially, all cell's next state is dead, we only need to care about when to be alive
        		if(board[i][j] == 0 && live_cnt == 3) {
        			board[i][j] = 2;   //00 --> 10
        		}
        		if(board[i][j] == 1 && live_cnt >= 2 && live_cnt <= 3) {
        			board[i][j] = 3;   //01 --> 11
        		}
        	}  //end n loop
        }  //end m loop
        //get the second states
        for(int i=0; i<m; i++) {
        	for(int j=0; j<n; j++) {
        		board[i][j] = board[i][j] >> 1;
        	}
        }
    }  //end gameOfLive function

    int liveNeighborCount(vector<vector<int>>& board, int m, int n, int i, int j) {
    	int live_cnt = 0;
    	for(int x = max(0, i-1); x <= min(m-1, i+1); x++) {
    		for(int y=max(0, j-1); y <= min(n-1, j+1); y++) {
    			live_cnt += (board[x][y] & 1);
    		}
    	}
    	live_cnt -= (board[i][j]&1);
    	return live_cnt;
    }
    
    int min(int a, int b) {
        if(a < b) return a;
        else return b;
    }
    
    int max(int a, int b) {
        if(a > b) return a;
        else return b;
    }
};