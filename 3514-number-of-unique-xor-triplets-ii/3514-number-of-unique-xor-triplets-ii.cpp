class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n < 3) {
            unordered_set<int> s;
            for (int x : nums) s.insert(x);
            return s.size();
        }

        // XOR values of all pairs
        unordered_set<int> pairs;
        for (int a : nums) {
            for (int b : nums) {
                pairs.insert(a ^ b);
            }
        }

        // XOR each pair value with every array element
        unordered_set<int> triplets;
        for (int x : pairs) {
            for (int a : nums) {
                triplets.insert(x ^ a);
            }
        }

        return triplets.size();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna