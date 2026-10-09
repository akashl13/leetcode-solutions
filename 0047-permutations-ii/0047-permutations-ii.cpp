
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        vector<bool> used(nums.size(), false);
        vector<int> path;

        backtrack(nums, used, path, result);
        return result;
    }

    void backtrack(vector<int>& nums, vector<bool>& used,
                   vector<int>& path,
                   vector<vector<int>>& result) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }

            // Skip duplicates at the same recursion level
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }

            used[i] = true;
            path.push_back(nums[i]);

            backtrack(nums, used, path, result);

            path.pop_back();
            used[i] = false;
        }
    }
};