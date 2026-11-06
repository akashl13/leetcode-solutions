class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        // Find longest sequential prefix
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        // Store all numbers present in nums
        unordered_set<int> st(nums.begin(), nums.end());

        // Find smallest missing number >= sum
        while (st.count(sum)) {
            sum++;
        }

        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna