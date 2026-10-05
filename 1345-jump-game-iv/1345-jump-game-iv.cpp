class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        if (n == 1)
            return 0;

        // Store all indices for each value
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        // BFS
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;

        int steps = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                int i = q.front();
                q.pop();

                // Reached last index
                if (i == n - 1)
                    return steps;

                // Jump i - 1
                if (i - 1 >= 0 && !visited[i - 1]) {
                    visited[i - 1] = true;
                    q.push(i - 1);
                }

                // Jump i + 1
                if (i + 1 < n && !visited[i + 1]) {
                    visited[i + 1] = true;
                    q.push(i + 1);
                }

                // Jump to indices with same value
                if (mp.count(arr[i])) {

                    for (int j : mp[arr[i]]) {

                        if (!visited[j]) {
                            visited[j] = true;
                            q.push(j);
                        }
                    }

                    // Important:
                    // We don't need this value's indices again
                    mp.erase(arr[i]);
                }
            }

            steps++;
        }

        return -1;
    }
};