
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;

        for (int x : nums) {
            if (k < 2 || x != nums[k - 2]) {
                nums[k] = x;
                k++;
            }
        }

        return k;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna