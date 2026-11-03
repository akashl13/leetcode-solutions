
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int highest = 0;

        for (int i = 0; i < gain.size(); i++) {
            altitude += gain[i];
            highest = max(highest, altitude);
        }

        return highest;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna