
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int ans = INT_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Land ride first, then water ride
                int landFinish = landStartTime[i] + landDuration[i];

                int waterFinish = max(landFinish, waterStartTime[j])
                                  + waterDuration[j];

                ans = min(ans, waterFinish);

                // Water ride first, then land ride
                int waterFirstFinish = waterStartTime[j] + waterDuration[j];

                int landFinishSecond = max(waterFirstFinish, landStartTime[i])
                                       + landDuration[i];

                ans = min(ans, landFinishSecond);
            }
        }

        return ans;
    }
};
