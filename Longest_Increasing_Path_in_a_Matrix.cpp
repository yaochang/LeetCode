class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
    		return 0;
    	}
        
        int m = matrix.size();
        int n = matrix[0].size();

        int** visit 		= new int*[m];
        int** maxvalue 	    = new int*[m];

        for(int i=0; i<m; i++) {
            visit[i] = new int[n];
            maxvalue[i] = new int[n];
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                visit[i][j] = 0;
                maxvalue[i][j] = 1;
            }
        }

        int ret = 1;
        for(int i=0; i<m; i++) {
        	for(int j=0; j<n; j++) {
        		if(ret < dfs(matrix,visit,maxvalue,m,n,i,j)) {
        			ret = dfs(matrix,visit,maxvalue,m,n,i,j);
        		}
        	}
        }

        for(int i=0; i<m; i++) {
        	delete [] maxvalue[i];
        	delete [] visit[i];
        }
        delete [] maxvalue;
        delete [] visit;
        return ret;
    }
    
    int dfs(vector<vector<int>>& matrix, int** visit, int** maxvalue, int m, int n, int i, int j) {
    	if(visit[i][j] == 1) {
    		return maxvalue[i][j];
    	}

    	if(i-1>=0) {
    		if(matrix[i-1][j] < matrix[i][j]) {
    		    maxvalue[i][j] = max(maxvalue[i][j], dfs(matrix,visit,maxvalue,m,n,i-1,j) + 1);
    		}
    	}
    	if(i+1<m) {
    		if(matrix[i+1][j] < matrix[i][j]) {
    			maxvalue[i][j] = max(maxvalue[i][j], dfs(matrix,visit,maxvalue,m,n,i+1,j) + 1);
    		}
    	}
    	if(j-1>=0) {
    		if(matrix[i][j-1] < matrix[i][j]) {
    			maxvalue[i][j] = max(maxvalue[i][j], dfs(matrix,visit,maxvalue,m,n,i,j-1) + 1);
    		}
    	}
    	if(j+1<n) {
    		if(matrix[i][j+1] < matrix[i][j]) {
    			maxvalue[i][j] = max(maxvalue[i][j], dfs(matrix,visit,maxvalue,m,n,i,j+1) + 1);
    		}
    	}
    	visit[i][j] = 1;
    	return maxvalue[i][j];
    }
    
    int max(int a, int b) {
        if(a > b) return a;
        else return b;
    }
};