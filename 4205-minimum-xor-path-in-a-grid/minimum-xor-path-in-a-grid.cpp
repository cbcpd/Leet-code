class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int dp[m][n][1024];
        // dp[i][j][k]=1 means there exist a path from (0,0) -> (i,j) such that the bitwise XOR value of all numbers along the path is exactly = k
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<1024;k++) dp[i][j][k]=-1;
            }
        }
        dp[0][0][grid[0][0]]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<1024;k++){
                    if(i>=1 && dp[i-1][j][k]!=-1) dp[i][j][k^grid[i][j]]=1;
                    if(j>=1 && dp[i][j-1][k]!=-1) dp[i][j][k^grid[i][j]]=1;
                }
            }
        }
        for(int i=0;i<1024;i++){
            if(dp[m-1][n-1][i]!=-1) return i;
        }
        assert(false);
        return -1;
    }
};