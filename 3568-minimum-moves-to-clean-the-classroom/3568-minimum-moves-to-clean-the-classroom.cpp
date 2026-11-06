class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;

        vector<pair<int, int>> litter;

        // Find starting point and all litter
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        // No litter
        if (k == 0)
            return 0;

        // Map litter cell -> bit number
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int i = 0; i < k; i++) {
            litterId[litter[i].first][litter[i].second] = i;
        }

        /*
            State:
            (row, col, energyLeft, mask)

            mask tells which litter has already been collected.
        */

        int totalMasks = 1 << k;

        // visited[r][c][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(totalMasks, false)
                )
            )
        );

        struct State {
            int r;
            int c;
            int e;
            int mask;
            int dist;
        };

        queue<State> q;

        visited[sr][sc][energy][0] = true;
        q.push({sr, sc, energy, 0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int fullMask = (1 << k) - 1;

        while (!q.empty()) {

            State cur = q.front();
            q.pop();

            int r = cur.r;
            int c = cur.c;
            int e = cur.e;
            int mask = cur.mask;
            int dist = cur.dist;

            // All litter collected
            if (mask == fullMask)
                return dist;

            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                // Outside grid
                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n)
                    continue;

                // Obstacle
                if (classroom[nr][nc] == 'X')
                    continue;

                // Need energy to make a move
                if (e == 0)
                    continue;

                int ne = e - 1;

                // Collect litter
                int newMask = mask;

                if (classroom[nr][nc] == 'L') {
                    int id = litterId[nr][nc];
                    newMask |= (1 << id);
                }

                // Reset energy at R
                if (classroom[nr][nc] == 'R') {
                    ne = energy;
                }

                if (!visited[nr][nc][ne][newMask]) {

                    visited[nr][nc][ne][newMask] = true;

                    q.push({
                        nr,
                        nc,
                        ne,
                        newMask,
                        dist + 1
                    });
                }
            }
        }

        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna