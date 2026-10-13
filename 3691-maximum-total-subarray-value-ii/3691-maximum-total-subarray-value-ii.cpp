class Solution {
public:
    using ll = long long;

    vector<vector<int>> mn, mx;
    vector<int> lg;
    int n;

    void buildSparseTable(vector<int>& nums) {
        lg.assign(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        int K = lg[n] + 1;
        mn.assign(K, vector<int>(n));
        mx.assign(K, vector<int>(n));

        for (int i = 0; i < n; i++) {
            mn[0][i] = mx[0][i] = nums[i];
        }

        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                mn[j][i] = min(
                    mn[j - 1][i],
                    mn[j - 1][i + (1 << (j - 1))]
                );

                mx[j][i] = max(
                    mx[j - 1][i],
                    mx[j - 1][i + (1 << (j - 1))]
                );
            }
        }
    }

    int getValue(int l, int r) {
        int j = lg[r - l + 1];

        int minimum = min(
            mn[j][l],
            mn[j][r - (1 << j) + 1]
        );

        int maximum = max(
            mx[j][l],
            mx[j][r - (1 << j) + 1]
        );

        return maximum - minimum;
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        n = nums.size();
        buildSparseTable(nums);

        // {subarray value, left endpoint, right endpoint}
        priority_queue<array<int, 3>> pq;

        for (int l = 0; l < n; l++) {
            pq.push({getValue(l, n - 1), l, n - 1});
        }

        ll ans = 0;

        while (k-- > 0 && !pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int value = cur[0];
            int l = cur[1];
            int r = cur[2];

            ans += value;

            if (r > l) {
                pq.push({getValue(l, r - 1), l, r - 1});
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna