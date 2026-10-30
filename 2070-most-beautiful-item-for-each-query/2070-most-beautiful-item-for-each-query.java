import java.util.*;

class Solution {
    public int[] maximumBeauty(int[][] items, int[] queries) {

        // Sort items by price
        Arrays.sort(items, (a, b) -> Integer.compare(a[0], b[0]));

        int n = items.length;

        // Store maximum beauty for each price
        int maxBeauty = 0;

        for (int i = 0; i < n; i++) {
            maxBeauty = Math.max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty;
        }

        int[] answer = new int[queries.length];

        // Process each query
        for (int i = 0; i < queries.length; i++) {

            int query = queries[i];

            int left = 0;
            int right = n - 1;
            int best = 0;

            // Binary search
            while (left <= right) {

                int mid = left + (right - left) / 2;

                if (items[mid][0] <= query) {

                    best = items[mid][1];
                    left = mid + 1;

                } else {

                    right = mid - 1;
                }
            }

            answer[i] = best;
        }

        return answer;
    }
}