class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.size();

        vector<bool> dp(n, false);

        // Starting position
        dp[0] = true;

        int reachable = 0;

        for (int i = 1; i < n; i++) {

            // Add the new index entering our valid window
            int add = i - minJump;

            if (add >= 0 && dp[add]) {
                reachable++;
            }

            // Remove the index leaving our valid window
            int remove = i - maxJump - 1;

            if (remove >= 0 && dp[remove]) {
                reachable--;
            }

            // i is reachable if:
            // 1. It is '0'
            // 2. There is at least one reachable position
            //    in the allowed jump range
            if (s[i] == '0' && reachable > 0) {
                dp[i] = true;
            }
        }

        return dp[n - 1];
    }
};