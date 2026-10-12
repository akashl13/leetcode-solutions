class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int totalSum = 0;

        for (int x : nums) {
            totalSum += x;
        }

        int leftSum = 0;
        vector<int> answer;

        for (int i = 0; i < nums.size(); i++) {
            int rightSum = totalSum - leftSum - nums[i];

            answer.push_back(abs(leftSum - rightSum));

            leftSum += nums[i];
        }

        return answer;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna