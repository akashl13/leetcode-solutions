class Solution {
public:
    int n;
    vector<int> dp;

    int dfs(vector<int>& arr, int i, int d) {

        // Already calculated
        if (dp[i] != -1)
            return dp[i];

        // At least the current index can be visited
        dp[i] = 1;

        // --------------------
        // Jump to the LEFT
        // --------------------
        for (int j = i - 1; j >= max(0, i - d); j--) {

            // Cannot jump through a bigger/equal value
            if (arr[j] >= arr[i])
                break;

            dp[i] = max(dp[i], 1 + dfs(arr, j, d));
        }

        // --------------------
        // Jump to the RIGHT
        // --------------------
        for (int j = i + 1; j <= min(n - 1, i + d); j++) {

            // Cannot jump through a bigger/equal value
            if (arr[j] >= arr[i])
                break;

            dp[i] = max(dp[i], 1 + dfs(arr, j, d));
        }

        return dp[i];
    }

    int maxJumps(vector<int>& arr, int d) {

        n = arr.size();

        // dp[i] = maximum number of indices
        // we can visit starting from i
        dp.assign(n, -1);

        int answer = 1;

        for (int i = 0; i < n; i++) {
            answer = max(answer, dfs(arr, i, d));
        }

        return answer;
    }
};