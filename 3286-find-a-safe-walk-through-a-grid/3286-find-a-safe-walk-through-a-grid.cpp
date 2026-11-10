class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        // best[i][j] = maximum health remaining when reaching (i, j)
        vector<vector<int>> best(m, vector<int>(n, -1));

        queue<pair<int, int>> q;

        int startHealth = health - grid[0][0];

        if (startHealth <= 0)
            return false;

        best[0][0] = startHealth;
        q.push({0, 0});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                int newHealth = best[r][c] - grid[nr][nc];

                // We must always have health >= 1
                if (newHealth <= 0)
                    continue;

                // Only visit if we reach this cell with more health
                if (newHealth > best[nr][nc]) {
                    best[nr][nc] = newHealth;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna