
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> nums;
        vector<int> fact(n + 1, 1);

        // Calculate factorials
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
            nums.push_back(i);
        }

        k--; // Convert to 0-based index

        while (n > 0) {
            int index = k / fact[n - 1];

            ans += to_string(nums[index]);
            nums.erase(nums.begin() + index);

            k %= fact[n - 1];
            n--;
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna