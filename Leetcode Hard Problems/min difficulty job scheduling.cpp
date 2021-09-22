class Solution {
public:
    int maxVal = 1e7;
    int helper(int d,int index,vector<int>& jobs,vector<vector<int>> &dp,int n)
    {
        if(index == n && d==0) return 0;
        if(d==0 || index==n || n-index < d) return maxVal;
        if(dp[index][d]!=-1) return dp[index][d];
        int ans = maxVal,maxele = 0;
        for (int i = index;i + d - 1< n ;i++)
        {
            maxele = max(maxele,jobs[i]);
            ans = min ( ans , maxele + helper(d-1 , i+1 , jobs,dp,n));
        }
        return dp[index][d] = ans;
        
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;
        vector<vector<int>> dp(n,vector<int>(d+1,-1));
        return helper(d,0,jobDifficulty,dp,n);
    }
};