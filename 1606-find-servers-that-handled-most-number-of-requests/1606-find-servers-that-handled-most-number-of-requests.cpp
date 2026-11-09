class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // Available server IDs
        set<int> available;

        // Initially all servers are available
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {finishTime, serverId}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busy;

        vector<int> count(k, 0);

        for (int i = 0; i < arrival.size(); i++) {

            // Free all servers whose requests are finished
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                int server = busy.top().second;
                busy.pop();

                available.insert(server);
            }

            // If all servers are busy, drop the request
            if (available.empty()) {
                continue;
            }

            // Preferred server
            int preferred = i % k;

            // Find first available server >= preferred
            auto it = available.lower_bound(preferred);

            // If none, wrap around to the smallest server
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // Remove from available
            available.erase(it);

            // Count request
            count[server]++;

            // Server becomes free after arrival[i] + load[i]
            busy.push({
                (long long)arrival[i] + load[i],
                server
            });
        }

        // Find maximum number of requests handled
        int maxRequests = *max_element(count.begin(), count.end());

        vector<int> answer;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxRequests) {
                answer.push_back(i);
            }
        }

        return answer;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna