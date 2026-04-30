class Solution {
    public int maxPathScore(int[][] grid, int k) {
        int m = grid.length; int n = grid[0].length;
         int dp[][][] = new int[m][n][k+1];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                for(int c=0; c<=k; c++){
                    dp[i][j][c] = -1;
                }
            }
        }
        int startVal = grid[0][0];
        int startScore = startVal;
        int startCost = (startVal == 0) ? 0 : 1;
        if (startCost <= k) dp[0][0][startCost] = startScore;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {
                    if (dp[i][j][c] == -1) continue;
                    if (j + 1 < n) {
                        int val = grid[i][j + 1];
                        int cost = (val == 0) ? 0 : 1;
                        int score = val;
                        if (c + cost <= k) {
                            dp[i][j + 1][c + cost] = Math.max(dp[i][j + 1][c + cost], dp[i][j][c] + score);
                        }
                    }
                    if (i + 1 < m) {
                        int val = grid[i + 1][j];
                        int cost = (val == 0) ? 0 : 1;
                        int score = val;
                        if (c + cost <= k) {
                            dp[i + 1][j][c + cost] = Math.max(dp[i + 1][j][c + cost], dp[i][j][c] + score);
                        }
                    }
                }
            }
        }
        int result = -1;
        for (int c = 0; c <= k; c++) {
            result = Math.max(result, dp[m - 1][n - 1][c]);
        }

        return result;
    }
}