class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int digitSum = 0;
        int digitProduct = 1;

        while (temp > 0) {
            int digit = temp % 10;

            digitSum += digit;
            digitProduct *= digit;

            temp /= 10;
        }

        int total = digitSum + digitProduct;

        return n % total == 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna