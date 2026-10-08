1class Solution {
2public:
3    int minPathSum(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        vector<int> dp(n);
8
9        dp[0] = grid[0][0];
10
11        // First row
12        for (int j = 1; j < n; j++) {
13            dp[j] = dp[j - 1] + grid[0][j];
14        }
15
16        // Remaining rows
17        for (int i = 1; i < m; i++) {
18            dp[0] += grid[i][0];
19
20            for (int j = 1; j < n; j++) {
21                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
22            }
23        }
24
25        return dp[n - 1];
26    }
27};