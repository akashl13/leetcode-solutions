
class Solution {
public:
    int minLength(string s, int numOps) {
        int n = s.size();

        auto check = [&](int limit) {
            int flips = 0;

            // Special case: every run must have length 1
            if (limit == 1) {
                int mismatch = 0;

                for (int i = 0; i < n; i++) {
                    if (s[i] != (i % 2 == 0 ? '0' : '1')) {
                        mismatch++;
                    }
                }

                return min(mismatch, n - mismatch) <= numOps;
            }

            // For limit >= 2, process consecutive equal characters
            int run = 0;

            for (int i = 0; i < n; i++) {
                run++;

                if (i == n - 1 || s[i] != s[i + 1]) {
                    flips += run / (limit + 1);
                    run = 0;

                    if (flips > numOps) {
                        return false;
                    }
                }
            }

            return flips <= numOps;
        };

        int left = 1, right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (check(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna