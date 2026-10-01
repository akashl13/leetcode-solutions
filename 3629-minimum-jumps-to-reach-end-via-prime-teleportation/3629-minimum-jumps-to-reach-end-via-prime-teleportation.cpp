class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 0;

        int maxVal = *max_element(nums.begin(), nums.end());

        // Smallest Prime Factor
        vector<int> spf(maxVal + 1);

        for (int i = 0; i <= maxVal; i++)
            spf[i] = i;

        for (int i = 2; i * i <= maxVal; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= maxVal; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        // primeIndices[p] = indices whose nums[index] is divisible by p
        vector<vector<int>> primeIndices(maxVal + 1);

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            while (x > 1) {
                int p = spf[x];

                primeIndices[p].push_back(i);

                // Skip duplicate prime factors
                while (x % p == 0)
                    x /= p;
            }
        }

        // BFS
        vector<int> dist(n, -1);
        vector<bool> usedPrime(maxVal + 1, false);

        queue<int> q;
        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            int d = dist[i];

            if (i == n - 1)
                return d;

            // Move left
            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = d + 1;
                q.push(i - 1);
            }

            // Move right
            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = d + 1;
                q.push(i + 1);
            }

            // Prime teleportation
            int x = nums[i];

            // Teleportation is available only if nums[i] itself is prime
            if (x >= 2 && spf[x] == x && !usedPrime[x]) {
                usedPrime[x] = true;

                for (int j : primeIndices[x]) {
                    if (dist[j] == -1) {
                        dist[j] = d + 1;
                        q.push(j);
                    }
                }
            }
        }

        return -1;
    }
};