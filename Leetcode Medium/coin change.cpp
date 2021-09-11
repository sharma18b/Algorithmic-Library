class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<int> dp(amount+1,INT_MAX);
        int n = coins.size();
        dp[0] = 0;
        for (int i=0;i<=amount;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i]!=INT_MAX && coins[j] <= amount)
                {
                    if(i + coins[j] > amount) break;
                else{
                    dp[i + coins[j]] = min(dp[i + coins[j]], dp[i] + 1);
                }
                }

            }
        }
        return dp[amount]==INT_MAX ? -1 : dp[amount];
    }
};
