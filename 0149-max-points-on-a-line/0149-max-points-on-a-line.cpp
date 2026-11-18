class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if (n <= 2)
            return n;

        int answer = 2;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> mp;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                int g = gcd(abs(dx), abs(dy));

                dx /= g;
                dy /= g;

                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }

                if (dx == 0)
                    dy = 1;

                if (dy == 0)
                    dx = 1;

                string slope = to_string(dy) + "/" + to_string(dx);

                mp[slope]++;
                answer = max(answer, mp[slope] + 1);
            }
        }

        return answer;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna