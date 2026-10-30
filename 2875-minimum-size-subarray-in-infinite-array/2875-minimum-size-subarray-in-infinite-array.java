class Solution {
    public int minSizeSubarray(int[] nums, int target) {

        int n = nums.length;
        long totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        // Complete repetitions
        long fullCycles = target / totalSum;
        long remaining = target % totalSum;

        // Minimum length
        int minLength = (int) (fullCycles * n);

        if (remaining == 0) {
            return minLength;
        }

        // Prefix sum and sliding window
        long sum = 0;
        int left = 0;
        int minWindow = Integer.MAX_VALUE;

        for (int right = 0; right < 2 * n; right++) {

            sum += nums[right % n];

            while (sum > remaining && left <= right) {
                sum -= nums[left % n];
                left++;
            }

            if (sum == remaining) {
                minWindow = Math.min(
                    minWindow,
                    right - left + 1
                );
            }
        }

        if (minWindow == Integer.MAX_VALUE) {
            return -1;
        }

        return minLength + minWindow;
    }
}