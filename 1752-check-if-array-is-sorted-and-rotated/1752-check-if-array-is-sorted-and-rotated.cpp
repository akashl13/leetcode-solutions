class Solution {
public:
    bool check(vector<int>& nums) {

        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            // Compare current element with next element
            // using circular indexing
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }

            // More than one drop means impossible
            if (count > 1) {
                return false;
            }
        }

        return true;
    }
};