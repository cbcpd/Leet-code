
class Solution {
public:
   long long maximumScore(vector<vector<int>>& grid) {
       int rows = grid.size(), cols = grid[0].size();
       vector<vector<long long>> prefix_sum(rows + 1, vector<long long>(cols + 1));
       for (int i = 0; i < rows; ++i) {
           for (int j = 0; j < cols; ++j) {
               prefix_sum[i + 1][j + 1] = grid[i][j] + prefix_sum[i][j + 1];
           }
       }
       memset(_memo, -1, sizeof(_memo));
       return find_score(grid, prefix_sum, 0, 0, 1);
   }
private:
   long long _memo[2][101][101];
   long long find_score(const vector<vector<int>>& grid, const vector<vector<long long>>& prefix_sum, int prev_len, bool prev_taken, int idx) {
       if (idx == grid[0].size() + 1) {
           return 0;
       }
       if (_memo[prev_taken][prev_len][idx] != -1)
           return _memo[prev_taken][prev_len][idx];
       long long res = 0;
       for (int len = 0; len <= grid.size(); ++len) {
           long long prev_score = prev_taken ? 0 : (prev_len >= len ? 0 : prefix_sum[len][idx - 1] - prefix_sum[prev_len][idx - 1]);
           long long score = len < prev_len ? prefix_sum[prev_len][idx] - prefix_sum[len][idx] : 0;
           res = max({res, prev_score + score + find_score(grid, prefix_sum, len, true, idx + 1), prev_score + find_score(grid, prefix_sum, len, false, idx + 1)});
       }
       return _memo[prev_taken][prev_len][idx] = res;
   }
};