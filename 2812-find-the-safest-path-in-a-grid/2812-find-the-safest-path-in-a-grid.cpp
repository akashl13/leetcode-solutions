#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // Step 1: Multi-source BFS from all thieves.
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    dist[r][c] = 0;
                    q.push({r, c});
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    dist[nr][nc] == -1) {

                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        // Step 2: Find the path maximizing its minimum distance.
        priority_queue<tuple<int, int, int>> pq;
        vector<vector<int>> best(n, vector<int>(n, -1));

        best[0][0] = dist[0][0];
        pq.push({best[0][0], 0, 0});

        while (!pq.empty()) {
            auto [safe, r, c] = pq.top();
            pq.pop();

            if (safe < best[r][c])
                continue;

            if (r == n - 1 && c == n - 1)
                return safe;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n) {

                    int newSafe = min(safe, dist[nr][nc]);

                    if (newSafe > best[nr][nc]) {
                        best[nr][nc] = newSafe;
                        pq.push({newSafe, nr, nc});
                    }
                }
            }
        }

        return 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna