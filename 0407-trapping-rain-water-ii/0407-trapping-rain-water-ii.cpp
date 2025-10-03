class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int rows = heightMap.size(), cols = heightMap[0].size(), water = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        priority_queue<Cell> pq;

        for (int i = 0; i < rows; i++) {
            pq.push(Cell(heightMap[i][0], i, 0));
            pq.push(Cell(heightMap[i][cols - 1], i, cols - 1));
            visited[i][0] = visited[i][cols - 1] = true;
        }
        for (int j = 0; j < cols; j++) {
            pq.push(Cell(heightMap[0][j], 0, j));
            pq.push(Cell(heightMap[rows - 1][j], rows - 1, j));
            visited[0][j] = visited[rows - 1][j] = true;
        }

        int dR[4] = {0, 0, -1, 1}, dC[4] = {-1, 1, 0, 0};
        while (!pq.empty()) {
            Cell cur = pq.top(); pq.pop();
            for (int d = 0; d < 4; d++) {
                int r = cur.getRow() + dR[d], c = cur.getCol() + dC[d];
                if (r >= 0 && c >= 0 && r < rows && c < cols && !visited[r][c]) {
                    water += max(0, cur.getHeight() - heightMap[r][c]);
                    pq.push(Cell(max(heightMap[r][c], cur.getHeight()), r, c));
                    visited[r][c] = true;
                }
            }
        }
        return water;
    }

private:
    class Cell {
        int height, row, col;
    public:
        Cell(int h, int r, int c) : height(h), row(r), col(c) {}
        int getHeight() const { return height; }
        int getRow() const { return row; }
        int getCol() const { return col; }
        bool operator<(const Cell& other) const { return height > other.height; }
    };
};