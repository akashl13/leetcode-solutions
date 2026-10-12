class Solution {
public:
    int solve(vector<int>& firstStart, vector<int>& firstDuration,
              vector<int>& secondStart, vector<int>& secondDuration) {

        int n = secondStart.size();

        vector<pair<int, int>> rides;
        for (int i = 0; i < n; i++) {
            rides.push_back({secondStart[i], secondDuration[i]});
        }

        sort(rides.begin(), rides.end());

        // Prefix minimum duration
        vector<int> prefix(n);
        prefix[0] = rides[0].second;

        for (int i = 1; i < n; i++) {
            prefix[i] = min(prefix[i - 1], rides[i].second);
        }

        // Suffix minimum of (start time + duration)
        vector<int> suffix(n);
        suffix[n - 1] = rides[n - 1].first + rides[n - 1].second;

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = min(suffix[i + 1],
                            rides[i].first + rides[i].second);
        }

        int ans = INT_MAX;

        for (int i = 0; i < firstStart.size(); i++) {
            int finish = firstStart[i] + firstDuration[i];

            // Find rides that have already opened by 'finish'
            int k = upper_bound(
                rides.begin(), rides.end(),
                make_pair(finish, INT_MAX)
            ) - rides.begin();

            // Second ride is already open
            if (k > 0) {
                ans = min(ans, finish + prefix[k - 1]);
            }

            // Second ride opens after the first ride finishes
            if (k < n) {
                ans = min(ans, suffix[k]);
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int landThenWater = solve(
            landStartTime, landDuration,
            waterStartTime, waterDuration
        );

        int waterThenLand = solve(
            waterStartTime, waterDuration,
            landStartTime, landDuration
        );

        return min(landThenWater, waterThenLand);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna