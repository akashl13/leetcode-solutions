class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            // Minimum is on the right side
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            // Minimum is on the left side including mid
            else {
                right = mid;
            }
        }

        return nums[left];
    }
};