class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        long long ans = 0;
        long long cost = 0;

        deque<int> dq;

        int right = n - 1;

        for (int left = n - 1; left >= 0; left--) {

            // Maintain decreasing values in deque
            while (!dq.empty() && nums[dq.back()] < nums[left]) {
                int mid = dq.back();
                dq.pop_back();

                int next = dq.empty() ? right + 1 : dq.back();

                // Elements from mid to next-1 need to be raised
                cost += 1LL * (next - mid) *
                        (nums[left] - nums[mid]);
            }

            dq.push_back(left);

            // Remove elements from the right while cost > k
            while (cost > k) {
                cost -= 1LL * (nums[dq.front()] - nums[right]);

                if (dq.front() == right) {
                    dq.pop_front();
                }

                right--;
            }

            // All subarrays [left ... right],
            // [left+1 ... right], ... are valid
            ans += right - left + 1;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna