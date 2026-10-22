
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        // Starting cell also consumes health if it contains 1
        dist[0][0] = grid[0][0];

        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        pq.push({dist[0][0], 0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [cost, r, c] = pq.top();
            pq.pop();

            if (cost != dist[r][c])
                continue;

            if (r == m - 1 && c == n - 1) {
                return cost < health;
            }

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                int newCost = cost + grid[nr][nc];

                if (newCost < dist[nr][nc]) {
                    dist[nr][nc] = newCost;
                    pq.push({newCost, nr, nc});
                }
            }
        }

        return false;
    }
};
