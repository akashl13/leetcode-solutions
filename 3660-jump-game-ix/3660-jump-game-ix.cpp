class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];

        // Minimum from i to the end
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        vector<int> ans(n);

        int prefixMax = nums[0];
        int start = 0;

        for (int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, nums[i]);

            // End of a block
            if (i == n - 1 || prefixMax <= suffixMin[i + 1]) {

                // Maximum value in this block
                for (int j = start; j <= i; j++) {
                    ans[j] = prefixMax;
                }

                start = i + 1;
                if (start < n) {
                    prefixMax = nums[start];
                }
            }
        }

        return ans;
    }
};