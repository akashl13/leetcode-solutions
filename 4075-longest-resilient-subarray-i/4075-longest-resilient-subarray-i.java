class Solution {
    public int resilientSubarray(int[] nums, int k) {
        int n = nums.length;
        int maxLength = 1;
        int left = 0;

        while (left < n) {
            int remainder = nums[left] % k;
            int right = left;

            // Find consecutive elements with the same remainder
            while (right < n && nums[right] % k == remainder) {
                right++;
            }

            int length = right - left;

            if (remainder == 0) {
                maxLength = Math.max(maxLength, length);
            } else {
                int period = k / gcd(remainder, k);

                int validLength = length - ((length - 1) % period);

                maxLength = Math.max(maxLength, validLength);
            }

            left = right;
        }

        return maxLength;
    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }
}