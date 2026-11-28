class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);
        long long minPrice = LLONG_MAX;

        for (auto& item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, (long long)item[1]);
        }

        vector<long long> d(n + 1, 0);

        for (int f = 1; f <= n; f++) {
            for (int j = f; j <= n; j += f) {
                d[f] += freq[j];
            }
            d[f]--;
        }

        vector<pair<long long, long long>> v;

        for (auto& item : items) {
            long long f = item[0];
            long long p = item[1];

            if (p < 2 * minPrice && d[f] > 0) {
                v.push_back({p, d[f]});
            }
        }

        sort(v.begin(), v.end());

        vector<long long> cnt(1, 0);
        vector<long long> cost(1, 0);

        for (auto [p, capacity] : v) {
            cnt.push_back(cnt.back() + capacity);
            cost.push_back(cost.back() + p * capacity);
        }

        auto can = [&](long long T) -> bool {
            long long q = min(T / 2, cnt.back());

            int idx = upper_bound(cnt.begin(), cnt.end(), q)
                      - cnt.begin() - 1;

            long long discountedCost = cost[idx];
            long long remaining = q - cnt[idx];

            if (idx < (int)v.size()) {
                discountedCost += remaining * v[idx].first;
            }

            long long totalCost =
                (T - 2 * q) * minPrice + discountedCost;

            return totalCost <= budget;
        };

        long long low = 0;
        long long high = 2LL * budget / minPrice + 1;

        while (low < high) {
            long long mid = low + (high - low + 1) / 2;

            if (can(mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        return (int)low;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna