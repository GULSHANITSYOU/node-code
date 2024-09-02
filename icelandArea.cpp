class Solution {
    int BFS(vector<vector<int>>& grid, int i, int j, int row, int col) {
        int deltaRC[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        q.push({i, j});

        grid[i][j] = 0;
        int sum = 0;

        while (q.size()) {
            auto [r, c] = q.front();
            q.pop();

            sum++;

            for (int i = 0; i < 4; i++) {
                int dr = r + deltaRC[i][0];
                int dc = c + deltaRC[i][1];

                if (dr >= row || dr < 0 || dc >= col || dc < 0 ||
                    grid[dr][dc] == 0)
                    continue;
                q.push({dr, dc});
                grid[dr][dc] = 0;
            }
        }

        return sum ; 
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        int res = INT_MIN;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    res = max(res, BFS(grid, i, j, row, col));
                }
            }
        }

        return res != INT_MIN ? res : 0;
    }
};