
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string current;
        backtrack(s, 0, 0, current, result);
        return result;
    }

private:
    void backtrack(string& s, int index, int parts,
                   string& current, vector<string>& result) {
        // If we have 4 parts, check whether all digits were used
        if (parts == 4) {
            if (index == s.size()) {
                result.push_back(current);
            }
            return;
        }

        // Try a part containing 1, 2, or 3 digits
        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {
            string part = s.substr(index, len);

            // Leading zeros are not allowed
            if (len > 1 && part[0] == '0') {
                break;
            }

            // Each part must be <= 255
            if (stoi(part) > 255) {
                break;
            }

            int oldSize = current.size();

            if (!current.empty()) {
                current += '.';
            }

            current += part;

            backtrack(s, index + len, parts + 1, current, result);

            // Backtrack: restore the previous string
            current.resize(oldSize);
        }
    }
};
