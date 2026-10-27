
class Solution {
public:
    string s;
    int pos = 0;

    set<string> parse() {
        set<string> result;
        set<string> current = {""};

        while (pos < s.size() && s[pos] != '}') {
            if (s[pos] == ',') {
                for (const string& word : current) {
                    result.insert(word);
                }
                current = {""};
                pos++;
            } else {
                set<string> part;

                if (s[pos] == '{') {
                    pos++;
                    part = parse();
                    pos++; // Skip '}'
                } else {
                    part.insert(string(1, s[pos]));
                    pos++;
                }

                set<string> combined;

                for (const string& a : current) {
                    for (const string& b : part) {
                        combined.insert(a + b);
                    }
                }

                current = combined;
            }
        }

        for (const string& word : current) {
            result.insert(word);
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;

        set<string> result = parse();

        return vector<string>(result.begin(), result.end());
    }
};
