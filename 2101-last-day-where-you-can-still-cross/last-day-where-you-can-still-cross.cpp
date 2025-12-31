
class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 0, high = cells.size() - 1;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (bfs(cells, row, col, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans + 1;
    }

    bool bfs(vector<vector<int>>& cells, int r, int c, int day) {
        vector<vector<int>> grid(r, vector<int>(c, 0));
        for (int i = 0; i <= day; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(r, vector<bool>(c, false));

        for (int j = 0; j < c; j++) {
            if (grid[0][j] == 0) {
                q.push({0, j});
                vis[0][j] = true;
            }
        }

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {-1, 1, 0, 0};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= r || ny >= c ||
                    grid[nx][ny] == 1 || vis[nx][ny])
                    continue;

                if (nx == r - 1) return true;

                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        return false;
    }
};