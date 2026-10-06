class Solution {
public:
    string multiply(string num1, string num2) {

        // If either number is 0
        if (num1 == "0" || num2 == "0")
            return "0";

        int m = num1.size();
        int n = num2.size();

        vector<int> result(m + n, 0);

        // Multiply every digit
        for (int i = m - 1; i >= 0; i--) {

            for (int j = n - 1; j >= 0; j--) {

                int a = num1[i] - '0';
                int b = num2[j] - '0';

                int product = a * b;

                int pos1 = i + j;
                int pos2 = i + j + 1;

                int sum = product + result[pos2];

                result[pos2] = sum % 10;
                result[pos1] += sum / 10;
            }
        }

        // Convert result to string
        string ans = "";

        int i = 0;

        // Skip leading zeros
        while (i < result.size() && result[i] == 0)
            i++;

        while (i < result.size()) {
            ans += char(result[i] + '0');
            i++;
        }

        return ans;
    }
};