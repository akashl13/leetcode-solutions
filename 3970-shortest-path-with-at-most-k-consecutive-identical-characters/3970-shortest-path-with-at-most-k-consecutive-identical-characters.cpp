class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> graph(n);

        for (auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
        }

        const long long INF = 1e18;

        // dist[node][cnt] = minimum cost to reach node
        // with cnt consecutive occurrences of labels[node].
        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        using State = tuple<long long, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        // Node 0 itself starts the consecutive sequence.
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [cost, u, cnt] = pq.top();
            pq.pop();

            if (cost != dist[u][cnt])
                continue;

            if (u == n - 1)
                return (int)cost;

            for (auto [v, w] : graph[u]) {
                int newCnt;

                if (labels[u] == labels[v])
                    newCnt = cnt + 1;
                else
                    newCnt = 1;

                if (newCnt > k)
                    continue;

                long long newCost = cost + w;

                if (newCost < dist[v][newCnt]) {
                    dist[v][newCnt] = newCost;
                    pq.push({newCost, v, newCnt});
                }
            }
        }

        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna