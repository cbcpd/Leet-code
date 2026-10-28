class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(); //rows
        int m = grid[0].size(); //columns

        //2d minimum sum -> dp point but here
        /*
        xor -> 
        (2)   
        (5)  =>> 2

        if the next element is 7 => 2^7 = 5
        5 ^ 7 = 2
        */

        /*
        2^10 = 1024 
        1023 = 11111111...
        */
        int maxi = 1024;
        vector<vector<vector<bool>>>dp(n,vector<vector<bool>>(m,vector<bool>(maxi,false)));

        dp[0][0][grid[0][0]]=true;
        //column initialization
        for(int i=1;i<n;i++){
            for(int x=0;x<maxi;x++){
                if(dp[i-1][0][x]){
                    dp[i][0][x^grid[i][0]]=true;
                }
            }
        }
        //row initialization
        for(int i=1;i<m;i++){
            for(int x=0;x<maxi;x++){
                if(dp[0][i-1][x]){
                    dp[0][i][x^grid[0][i]]=true;
                }
            }
        }
        //dp intialization (1,1) -> (n-1,m-1)
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                for(int x=0;x<maxi;x++){
                    if(dp[i-1][j][x] || dp[i][j-1][x]){
                        dp[i][j][x^grid[i][j]]=true;
                    }
                }
            }
        }

        for(int x=0;x<maxi;x++){
            if(dp[n-1][m-1][x]) return x; 
        }
        return -1;
    }
};