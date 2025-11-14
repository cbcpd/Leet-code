
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> arr(n,vector<int>(n,0));
        for(int q=0;q<queries.size();q++){
            int r1 = queries[q][0];
            int c1 = queries[q][1];
            int r2 = queries[q][2];
            int c2 = queries[q][3];
            for(int i=r1;i<=r2;i++){
                arr[i][c1]++;
                if((c2+1) < n)
                    arr[i][c2+1]--;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                arr[i][j] += arr[i][j-1];
            }
        }
        return arr;
    }
};