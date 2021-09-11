class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n =prices.size();
        if(n==0 || k==0) return 0;
        vector<vector<int>> dp(k+1,vector<int>(n,0));
        for (int t=1;t<=k;t++)
        {
            int prevdiff = INT_MIN;
            for (int i=1;i<n;i++)
            {
                if(i==0 || t==0) dp[t][i] = 0;
                else
                {
                    prevdiff = max(prevdiff, dp[t-1][i-1] - prices[i-1]);
                    dp[t][i] = max(dp[t][i-1] , prices[i] + prevdiff);
                }
            }
        }
        return dp[k][n-1];

    }
};
