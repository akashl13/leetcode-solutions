
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;

        // {x, height, type}
        // type = 0 means start, 1 means end
        vector<tuple<int, int, int>> events;

        for (auto& b : buildings) {
            events.push_back({b[0], -b[2], 0});
            events.push_back({b[1], b[2], 1});
        }

        sort(events.begin(), events.end());

        multiset<int> heights;
        heights.insert(0);

        int prevHeight = 0;

        for (auto& [x, h, type] : events) {

            if (type == 0) {
                // Building starts
                heights.insert(-h);
            }
            else {
                // Building ends
                heights.erase(heights.find(h));
            }

            int currHeight = *heights.rbegin();

            if (currHeight != prevHeight) {
                ans.push_back({x, currHeight});
                prevHeight = currHeight;
            }
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna