class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest = *min_element(nums.begin(), nums.end());
        int largest = *max_element(nums.begin(), nums.end());

        return gcd(smallest, largest);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna