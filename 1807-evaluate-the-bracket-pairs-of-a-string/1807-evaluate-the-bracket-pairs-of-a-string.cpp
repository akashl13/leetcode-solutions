class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        // Store knowledge in the map
        for (auto& item : knowledge) {
            mp[item[0]] = item[1];
        }

        string ans;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                string key = "";

                i++; // Skip '('

                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }

                // If key exists, use its value
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                }
                else {
                    ans += "?";
                }
            }
            else {
                ans += s[i];
            }
        }

        return ans;
    }
};