1class Solution {
2public:
3    bool isNumber(string s) {
4        bool seenDigit = false;
5        bool seenDot = false;
6        bool seenExp = false;
7        bool digitAfterExp = true;
8
9        for (int i = 0; i < s.length(); i++) {
10            char c = s[i];
11
12            // Digit
13            if (isdigit(c)) {
14                seenDigit = true;
15
16                if (seenExp)
17                    digitAfterExp = true;
18            }
19
20            // Decimal point
21            else if (c == '.') {
22                if (seenDot || seenExp)
23                    return false;
24
25                seenDot = true;
26            }
27
28            // Exponent
29            else if (c == 'e' || c == 'E') {
30                if (seenExp || !seenDigit)
31                    return false;
32
33                seenExp = true;
34                digitAfterExp = false;
35            }
36
37            // Sign
38            else if (c == '+' || c == '-') {
39                if (i != 0 &&
40                    s[i - 1] != 'e' &&
41                    s[i - 1] != 'E') {
42                    return false;
43                }
44            }
45
46            // Anything else
47            else {
48                return false;
49            }
50        }
51
52        return seenDigit && digitAfterExp;
53    }
54};