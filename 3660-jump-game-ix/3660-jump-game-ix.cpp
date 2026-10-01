class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> suffixMin(n);

        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        vector<int> ans(n);

        int prefixMax = INT_MIN;
        int blockMax = INT_MIN;
        int start = 0;

        for (int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, nums[i]);
            blockMax = max(blockMax, nums[i]);

            if (i == n - 1 || prefixMax <= suffixMin[i + 1]) {
                for (int j = start; j <= i; j++) {
                    ans[j] = blockMax;
                }

                start = i + 1;
                blockMax = INT_MIN;
            }
        }

        return ans;
    }
};