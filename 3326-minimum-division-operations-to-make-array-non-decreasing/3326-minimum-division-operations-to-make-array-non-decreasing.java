class Solution {

    public int minOperations(int[] nums) {

        int n = nums.length;
        int operations = 0;

        // Traverse from right to left
        for (int i = n - 2; i >= 0; i--) {

            // If current element is greater than next element
            if (nums[i] > nums[i + 1]) {

                // Find smallest prime factor
                int smallest = smallestPrimeFactor(nums[i]);

                // Divide current number by its greatest proper divisor
                nums[i] = smallest;

                // If still greater, impossible
                if (nums[i] > nums[i + 1]) {
                    return -1;
                }

                operations++;
            }
        }

        return operations;
    }

    // Find smallest prime factor
    private int smallestPrimeFactor(int x) {

        for (int i = 2; i * i <= x; i++) {

            if (x % i == 0) {
                return i;
            }
        }

        // If prime, return itself
        return x;
    }
}