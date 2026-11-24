
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> sum, mn, mx;

            for (int j = i; j < n; j++) {
                int x = nums[j];
                unordered_map<int, int> cnt;

                for (int p = 2; p * p <= x; p++) {
                    while (x % p == 0) {
                        cnt[p]++;
                        x /= p;
                    }
                }

                if (x > 1) cnt[x]++;

                for (auto &[p, c] : cnt) {
                    sum[p] += c;
                    mx[p] = max(mx[p], c);
                    if (!mn.count(p)) mn[p] = c;
                    else mn[p] = min(mn[p], c);
                }

                // Recalculate minimum exponents for primes
                // missing from the current element.
                bool valid = true;

                for (auto &[p, s] : sum) {
                    int minimum = INT_MAX;

                    for (int k = i; k <= j; k++) {
                        int v = nums[k], c = 0;
                        while (v % p == 0) {
                            v /= p;
                            c++;
                        }
                        minimum = min(minimum, c);
                    }

                    if (s != minimum + mx[p]) {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};





// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna