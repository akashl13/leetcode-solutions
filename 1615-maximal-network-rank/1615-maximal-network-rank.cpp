
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        bool connected[100][100] = {};

        // Count direct roads for each city
        for (auto& road : roads) {
            int a = road[0];
            int b = road[1];

            degree[a]++;
            degree[b]++;

            connected[a][b] = true;
            connected[b][a] = true;
        }

        int ans = 0;

        // Check every pair of different cities
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = degree[i] + degree[j];

                // Subtract the shared road if it exists
                if (connected[i][j]) {
                    rank--;
                }

                ans = max(ans, rank);
            }
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna