class Solution {
public:
    int t[101][101]; // memo table

    int solve(int i, int j, int m, int n, vector<vector<int>>& grid) {
        // Out of bounds or obstacle
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1) {
            return 0;
        }

        // Destination reached
        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        // Already computed
        if (t[i][j] != -1) {
            return t[i][j];
        }

        // Move down and right
        int down = solve(i + 1, j, m, n, grid);
        int right = solve(i, j + 1, m, n, grid);

        return t[i][j] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        memset(t, -1, sizeof(t));
        return solve(0, 0, m, n, grid);
    }
};
