
class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Store each number with its digit sum
        vector<pair<int, int>> arr;
        for (int x : nums) {
            arr.push_back({digitSum(x), x});
        }

        // Sort by digit sum, then by number
        sort(arr.begin(), arr.end());

        // Map each original number to its sorted position
        unordered_map<int, int> target;
        for (int i = 0; i < n; i++) {
            target[arr[i].second] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        // Count cycles in the permutation
        for (int i = 0; i < n; i++) {
            if (visited[i] || target[nums[i]] == i) {
                continue;
            }

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = target[nums[j]];
                cycleSize++;
            }

            if (cycleSize > 1) {
                swaps += cycleSize - 1;
            }
        }

        return swaps;
    }
};
