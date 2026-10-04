1class Solution {
2public:
3    int searchInsert(vector<int>& nums, int target) {
4        int left = 0;
5        int right = nums.size() - 1;
6
7        while (left <= right) {
8            int mid = left + (right - left) / 2;
9
10            if (nums[mid] == target) {
11                return mid;
12            }
13            else if (nums[mid] < target) {
14                left = mid + 1;
15            }
16            else {
17                right = mid - 1;
18            }
19        }
20
21        return left;
22    }
23};