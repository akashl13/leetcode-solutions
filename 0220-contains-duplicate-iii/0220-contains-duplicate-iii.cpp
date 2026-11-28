
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (indexDiff <= 0 || valueDiff < 0)
            return false;

        multiset<long long> st;

        for (int i = 0; i < nums.size(); i++) {

            // Remove elements outside the sliding window
            if (i > indexDiff) {
                st.erase(st.find(nums[i - indexDiff - 1]));
            }

            long long low = (long long)nums[i] - valueDiff;
            long long high = (long long)nums[i] + valueDiff;

            // Check if any element exists in the valid range
            auto it = st.lower_bound(low);

            if (it != st.end() && *it <= high) {
                return true;
            }

            st.insert(nums[i]);
        }

        return false;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna