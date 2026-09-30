class Solution {
public:
    
    // Parse one expression
    set<string> parse(string& expression, int& i) {
        set<string> result;
        set<string> current = {""};

        while (i < expression.size() && expression[i] != '}') {
            
            if (expression[i] == ',') {
                // Union
                for (string word : current) {
                    result.insert(word);
                }

                current = {""};
                i++;
            }
            else {
                set<string> part;

                if (expression[i] == '{') {
                    i++; // Skip '{'
                    part = parse(expression, i);
                    i++; // Skip '}'
                }
                else {
                    part.insert(string(1, expression[i]));
                    i++;
                }

                // Concatenate current × part
                set<string> next;

                for (string a : current) {
                    for (string b : part) {
                        next.insert(a + b);
                    }
                }

                current = next;
            }
        }

        // Add final part
        for (string word : current) {
            result.insert(word);
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> result = parse(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};