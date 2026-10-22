
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(51, 0);

        // Check every subarray of size k
        for (int i = 0; i <= n - k; i++) {
            bool seen[51] = {};

            for (int j = i; j < i + k; j++) {
                seen[nums[j]] = true;
            }

            // Count each number at most once per subarray
            for (int x = 0; x <= 50; x++) {
                if (seen[x]) {
                    freq[x]++;
                }
            }
        }

        // Find the largest number appearing in exactly one subarray
        for (int x = 50; x >= 0; x--) {
            if (freq[x] == 1) {
                return x;
            }
        }

        return -1;
    }
};
