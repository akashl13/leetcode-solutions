class Solution {
public:
    string entityParser(string text) {
        string ans;

        for (int i = 0; i < text.size(); i++) {

            if (text.substr(i, 6) == "&quot;") {
                ans += '"';
                i += 5;
            }
            else if (text.substr(i, 6) == "&apos;") {
                ans += '\'';
                i += 5;
            }
            else if (text.substr(i, 5) == "&amp;") {
                ans += '&';
                i += 4;
            }
            else if (text.substr(i, 4) == "&gt;") {
                ans += '>';
                i += 3;
            }
            else if (text.substr(i, 4) == "&lt;") {
                ans += '<';
                i += 3;
            }
            else if (text.substr(i, 7) == "&frasl;") {
                ans += '/';
                i += 6;
            }
            else {
                ans += text[i];
            }
        }

        return ans;
    }
};