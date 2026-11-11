class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());

        // Forward pass: enforce restrictions from left to right.
        for (int i = 1; i < restrictions.size(); i++) {
            int dist = restrictions[i][0] - restrictions[i - 1][0];

            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i - 1][1] + dist
            );
        }

        // Backward pass: enforce restrictions from right to left.
        for (int i = (int)restrictions.size() - 2; i >= 0; i--) {
            int dist = restrictions[i + 1][0] - restrictions[i][0];

            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] + dist
            );
        }

        int ans = 0;

        for (int i = 1; i < restrictions.size(); i++) {
            long long leftHeight = restrictions[i - 1][1];
            long long rightHeight = restrictions[i][1];
            long long dist = restrictions[i][0] - restrictions[i - 1][0];

            long long peak = (leftHeight + rightHeight + dist) / 2;
            ans = max(ans, (int)peak);
        }

        // Buildings after the final restriction can rise by 1 per building.
        ans = max(ans, restrictions.back()[1] + n - restrictions.back()[0]);

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna