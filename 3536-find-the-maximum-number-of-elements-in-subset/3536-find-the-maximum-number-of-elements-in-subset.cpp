
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        int ans = 1;

        // Special case: 1 can form an odd-length subset
        if (freq.count(1)) {
            int count = freq[1];
            ans = max(ans, count % 2 ? count : count - 1);
        }

        // Try every distinct number as the starting element
        for (auto& p : freq) {
            long long x = p.first;

            if (x == 1) continue;

            int length = 1;

            while (true) {
                long long next = x * x;

                if (next > 1000000000LL ||
                    freq[x] < 2 ||
                    freq.find(next) == freq.end()) {
                    break;
                }

                length += 2;
                x = next;
            }

            ans = max(ans, length);
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna