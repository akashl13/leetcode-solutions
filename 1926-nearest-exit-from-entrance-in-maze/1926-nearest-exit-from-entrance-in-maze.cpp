class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<pair<int, int>, int>> q;
        q.push({{entrance[0], entrance[1]}, 0});

        maze[entrance[0]][entrance[1]] = '+';

        int dirs[4][2] = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int r = curr.first.first;
            int c = curr.first.second;
            int steps = curr.second;

            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if (maze[nr][nc] == '+')
                    continue;

                if (nr == 0 || nr == m - 1 || nc == 0 || nc == n - 1)
                    return steps + 1;

                maze[nr][nc] = '+';
                q.push({{nr, nc}, steps + 1});
            }
        }

        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna