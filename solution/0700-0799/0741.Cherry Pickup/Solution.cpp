class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n << 1, vector<vector<int>>(n, vector<int>(n, -1e9)));
        dp[0][0][0] = grid[0][0];
        for (int k = 1; k < 2 * n - 1; ++k)
        {
            for (int i1 = 0; i1 < n; ++i1)
            {
                for (int i2 = 0; i2 < n; ++i2)
                {
                    int j1 = k - i1, j2 = k - i2;
                    if (j1 >= 0 && j1 < n && j2 >= 0 && j2 < n)
                    {
                        if (grid[i1][j1] == -1 || grid[i2][j2] == -1) continue;
                        int t = grid[i1][j1];
                        if (i1 != i2) t += grid[i2][j2];
                        for (int p1 = i1 - 1; p1 <= i1; ++p1)
                        {
                            for (int p2 = i2 - 1; p2 <= i2; ++p2)
                            {
                                if (p1 >= 0 && p2 >= 0) dp[k][i1][i2] = max(dp[k][i1][i2], dp[k - 1][p1][p2] + t);
                            }
                        }
                    }
                }
            }
        }
        return max(dp[2 * n - 2][n - 1][n - 1], 0);
    }
};