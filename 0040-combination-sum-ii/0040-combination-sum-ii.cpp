class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int target,
                   int start, vector<int>& current) {

        // Found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Since array is sorted, no need to continue
            if (candidates[i] > target)
                break;

            // Skip duplicates at the same level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Choose
            current.push_back(candidates[i]);

            // Explore
            // i + 1 because each number can be used only once
            backtrack(candidates, target - candidates[i],
                      i + 1, current);

            // Undo
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                         int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> current;

        backtrack(candidates, target, 0, current);

        return result;
    }
};