class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        // {weight, index}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > free;

        // {finishTime, weight, index}
        using T = tuple<long long, int, int>;

        priority_queue<
            T,
            vector<T>,
            greater<T>
        > busy;

        // Initially all servers are free
        for (int i = 0; i < servers.size(); i++) {
            free.push({servers[i], i});
        }

        vector<int> ans;

        long long time = 0;

        for (int i = 0; i < tasks.size(); i++) {

            // Task i arrives at second i
            time = max(time, (long long)i);

            // Move all servers that have finished by 'time'
            while (!busy.empty() &&
                   get<0>(busy.top()) <= time) {

                auto [finish, weight, index] = busy.top();
                busy.pop();

                free.push({weight, index});
            }

            // If no server is free, jump to the earliest
            // time when a server becomes free.
            if (free.empty()) {

                time = get<0>(busy.top());

                while (!busy.empty() &&
                       get<0>(busy.top()) <= time) {

                    auto [finish, weight, index] = busy.top();
                    busy.pop();

                    free.push({weight, index});
                }
            }

            // Select the best free server
            auto [weight, index] = free.top();
            free.pop();

            ans.push_back(index);

            // Server becomes free after task finishes
            busy.push({
                time + tasks[i],
                weight,
                index
            });
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna