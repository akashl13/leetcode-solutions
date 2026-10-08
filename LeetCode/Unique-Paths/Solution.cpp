1class Solution
2{
3    public:
4    int uniquePaths(int m, int n)
5    {
6        vector<int> dp(n,1);
7        for (int i=1; i<m; i++)
8        {
9            for(int j=1; j<n; j++)
10            {
11                dp[j]= dp[j]+dp[j-1];
12            }
13        }
14        return dp[n-1];
15
16    }
17};