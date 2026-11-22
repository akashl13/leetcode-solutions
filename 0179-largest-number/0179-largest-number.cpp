
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;

        for (int n : nums) {
            arr.push_back(to_string(n));
        }

        sort(arr.begin(), arr.end(), [](string a, string b) {
            return a + b > b + a;
        });

        if (arr[0] == "0") {
            return "0";
        }

        string ans = "";

        for (string s : arr) {
            ans += s;
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna