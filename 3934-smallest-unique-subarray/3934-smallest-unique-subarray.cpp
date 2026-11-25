
class Solution {
public:
    using ull = unsigned long long;

    bool check(vector<int>& nums, int k) {
        int n = nums.size();
        const ull B = 1000003;

        vector<ull> power(n + 1, 1), hash(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            power[i] = power[i - 1] * B;
            hash[i] = hash[i - 1] * B + nums[i - 1];
        }

        unordered_map<ull, int> freq;

        for (int i = 0; i + k <= n; i++) {
            ull h = hash[i + k] - hash[i] * power[k];

            if (++freq[h] == 1) {
                // Continue counting all occurrences.
            }
        }

        for (auto &p : freq) {
            if (p.second == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int low = 1, high = n, ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(nums, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna