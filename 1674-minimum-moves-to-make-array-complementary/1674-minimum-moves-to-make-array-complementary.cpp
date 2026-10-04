class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        // diff[s] will help calculate the number of moves
        // needed to make every pair sum equal to s.
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            int low = min(a, b);
            int high = max(a, b);

            int sum = a + b;

            // Initially assume 2 moves for every possible sum.

            // For sums from low + 1 to high + limit:
            // only 1 move is needed.
            diff[low + 1]--;
            diff[high + limit + 1]++;

            // For the exact current sum:
            // 0 moves are needed.
            diff[sum]--;
            diff[sum + 1]++;

            // 2 moves are automatically handled by the base cost.
        }

        int ans = n;
        int moves = n;

        for (int target = 2; target <= 2 * limit; target++) {
            moves += diff[target];
            ans = min(ans, moves);
        }

        return ans;
    }
};