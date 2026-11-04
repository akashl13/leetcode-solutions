
class Solution {
    public int[] sumAndMultiply(String s, int[][] queries) {

        long MOD = 1000000007L;
        int n = s.length();

        // Store positions of non-zero digits
        int[] pos = new int[n];
        long[] prefixSum = new long[n + 1];
        long[] prefixValue = new long[n + 1];

        int count = 0;

        for (int i = 0; i < n; i++) {
            int digit = s.charAt(i) - '0';

            if (digit != 0) {
                pos[count] = i;

                prefixSum[count + 1] =
                    prefixSum[count] + digit;

                prefixValue[count + 1] =
                    (prefixValue[count] * 10 + digit) % MOD;

                count++;
            }
        }

        // Precompute powers of 10
        long[] pow10 = new long[count + 1];
        pow10[0] = 1;

        for (int i = 1; i <= count; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        int[] ans = new int[queries.length];

        for (int q = 0; q < queries.length; q++) {

            int l = queries[q][0];
            int r = queries[q][1];

            // First non-zero digit at position >= l
            int left = lowerBound(pos, count, l);

            // First non-zero digit at position > r
            int right = upperBound(pos, count, r);

            // No non-zero digits
            if (left == right) {
                ans[q] = 0;
                continue;
            }

            int len = right - left;

            // Calculate sum of digits
            long sum = prefixSum[right] - prefixSum[left];

            // Calculate concatenated number
            long x = (
                prefixValue[right]
                - prefixValue[left] * pow10[len] % MOD
                + MOD
            ) % MOD;

            // Final answer
            ans[q] = (int) (x * sum % MOD);
        }

        return ans;
    }

    // First index whose position >= target
    private int lowerBound(int[] arr, int n, int target) {
        int low = 0, high = n;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }

    // First index whose position > target
    private int upperBound(int[] arr, int n, int target) {
        int low = 0, high = n;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
}
