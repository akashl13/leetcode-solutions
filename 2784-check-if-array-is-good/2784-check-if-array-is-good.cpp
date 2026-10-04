class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());

        // base[n] has n + 1 elements
        if (nums.size() != n + 1)
            return false;

        vector<int> freq(n + 1, 0);

        for (int x : nums) {
            // Values outside 1...n are invalid
            if (x < 1 || x > n)
                return false;

            freq[x]++;
        }

        // 1 to n-1 must appear exactly once
        for (int x = 1; x < n; x++) {
            if (freq[x] != 1)
                return false;
        }

        // n must appear exactly twice
        return freq[n] == 2;
    }
};