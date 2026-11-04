
class Solution {

    public long findKthSmallest(int[] coins, int k) {

        long low = 1;
        long minCoin = Integer.MAX_VALUE;

        for (int c : coins) {
            minCoin = Math.min(minCoin, c);
        }

        long high = minCoin * k;

        // Binary search
        while (low < high) {

            long mid = low + (high - low) / 2;

            if (countAmounts(coins, mid) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }

    private long countAmounts(int[] coins, long num) {

        int n = coins.length;
        long count = 0;

        // Inclusion-exclusion over all subsets
        for (int mask = 1; mask < (1 << n); mask++) {

            long lcm = 1;
            int bits = 0;
            boolean tooLarge = false;

            for (int i = 0; i < n; i++) {

                if ((mask & (1 << i)) != 0) {

                    bits++;

                    int c = coins[i];

                    long gcd = gcd(lcm, c);

                    // Avoid overflow and ignore LCM > num
                    if (lcm / gcd > num / c) {
                        tooLarge = true;
                        break;
                    }

                    lcm = (lcm / gcd) * c;
                }
            }

            if (tooLarge) {
                continue;
            }

            long multiples = num / lcm;

            if (bits % 2 == 1) {
                count += multiples;
            } else {
                count -= multiples;
            }
        }

        return count;
    }

    private long gcd(long a, long b) {

        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }
}
