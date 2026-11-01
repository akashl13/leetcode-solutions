
#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Factors {
        int a = 0; // Power of 2
        int b = 0; // Power of 3
        int c = 0; // Power of 5
        int d = 0; // Power of 7
    };

    Factors factorize(long long x) {
        Factors f;

        while (x > 0 && x % 2 == 0) {
            f.a++;
            x /= 2;
        }
        while (x > 0 && x % 3 == 0) {
            f.b++;
            x /= 3;
        }
        while (x > 0 && x % 5 == 0) {
            f.c++;
            x /= 5;
        }
        while (x > 0 && x % 7 == 0) {
            f.d++;
            x /= 7;
        }

        return f;
    }

    Factors digitFactor(int digit) {
        if (digit == 0) return Factors{};
        return factorize(digit);
    }

    Factors add(Factors x, Factors y) {
        return {
            x.a + y.a,
            x.b + y.b,
            x.c + y.c,
            x.d + y.d
        };
    }

    Factors subtract(Factors x, Factors y) {
        return {
            max(0, x.a - y.a),
            max(0, x.b - y.b),
            max(0, x.c - y.c),
            max(0, x.d - y.d)
        };
    }

    // Minimum digits required to supply the missing factors.
    int minDigits(Factors f) {
        int best = INT_MAX;

        // Use k digits of 6, each contributing one 2 and one 3.
        for (int k = 0; k <= min(f.a, f.b); k++) {
            int twos = f.a - k;
            int threes = f.b - k;

            int count = k
                      + (twos + 2) / 3   // 8 supplies 2^3
                      + (threes + 1) / 2 // 9 supplies 3^2
                      + f.c               // 5 supplies 5
                      + f.d;              // 7 supplies 7

            best = min(best, count);
        }

        return best;
    }

    // Construct the lexicographically smallest valid suffix.
    string build(int len, Factors need) {
        string ans;
        ans.reserve(len);

        for (int i = 0; i < len; i++) {
            int remainingSlots = len - i - 1;

            for (int digit = 1; digit <= 9; digit++) {
                Factors remaining =
                    subtract(need, digitFactor(digit));

                if (minDigits(remaining) <= remainingSlots) {
                    ans.push_back(char('0' + digit));
                    need = remaining;
                    break;
                }
            }
        }

        return ans;
    }

public:
    string smallestNumber(string num, long long t) {
        Factors target;
        long long x = t;

        while (x % 2 == 0) {
            target.a++;
            x /= 2;
        }
        while (x % 3 == 0) {
            target.b++;
            x /= 3;
        }
        while (x % 5 == 0) {
            target.c++;
            x /= 5;
        }
        while (x % 7 == 0) {
            target.d++;
            x /= 7;
        }

        // Other prime factors cannot occur in a digit product.
        if (x != 1) return "-1";

        int n = (int)num.size();

        vector<Factors> pref(n + 1);
        vector<int> zeros(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = add(
                pref[i], digitFactor(num[i] - '0')
            );

            zeros[i + 1] =
                zeros[i] + (num[i] == '0');
        }

        // Return num if it is already a valid answer.
        if (zeros[n] == 0 &&
            minDigits(subtract(target, pref[n])) == 0) {
            return num;
        }

        // Change the rightmost possible position first.
        for (int i = n - 1; i >= 0; i--) {
            // The unchanged prefix must contain no zeros.
            if (zeros[i] != 0) continue;

            for (int digit = (num[i] - '0') + 1;
                 digit <= 9; digit++) {

                Factors used = add(
                    pref[i], digitFactor(digit)
                );

                Factors need = subtract(target, used);
                int suffixLen = n - i - 1;

                if (minDigits(need) <= suffixLen) {
                    string ans = num.substr(0, i);
                    ans.push_back(char('0' + digit));
                    ans += build(suffixLen, need);

                    return ans;
                }
            }
        }

        // No valid answer of the same length.
        int len = max(n + 1, minDigits(target));

        return build(len, target);
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna