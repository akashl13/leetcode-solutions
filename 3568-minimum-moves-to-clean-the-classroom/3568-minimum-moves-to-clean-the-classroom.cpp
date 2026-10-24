
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<vector<int>> litterId(m, vector<int>(n, -1));
        int sx = 0, sy = 0, litterCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                } else if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }

        if (litterCount == 0) return 0;

        int fullMask = (1 << litterCount) - 1;

        // State: row, column, remaining energy, collected litter mask
        queue<array<int, 4>> q;
        q.push({sx, sy, energy, 0});

        // Maximum energy already seen for each position and mask
        vector<vector<vector<int>>> bestEnergy(
            m, vector<vector<int>>(n, vector<int>(1 << litterCount, -1))
        );

        bestEnergy[sx][sy][0] = energy;

        int dirs[5] = {-1, 0, 1, 0, -1};
        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [x, y, e, mask] = q.front();
                q.pop();

                if (mask == fullMask) return moves;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dirs[d];
                    int ny = y + dirs[d + 1];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;

                    if (classroom[nx][ny] == 'X' || e == 0)
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    if (classroom[nx][ny] == 'L') {
                        nmask |= (1 << litterId[nx][ny]);
                    }

                    if (classroom[nx][ny] == 'R') {
                        ne = energy;
                    }

                    if (ne <= bestEnergy[nx][ny][nmask])
                        continue;

                    bestEnergy[nx][ny][nmask] = ne;
                    q.push({nx, ny, ne, nmask});
                }
            }

            moves++;
        }

        return -1;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna