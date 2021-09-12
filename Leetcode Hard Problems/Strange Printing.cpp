class Solution {
public:
    int dp[101][101];
    int helper(int i,int j,string s)
    {
        if( i > j) return 0;
        if (i==j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int res = INT_MAX;
        res = min(res ,  1 + helper(i+1,j,s));
        for (int k = i+1;k<=j;k++)
        {
            if(s[i]==s[k])
            res = min(res , helper(i , k - 1, s) + helper(k+1, j ,s));
        }
        dp[i][j] = res;
        return res;
    }
    
    int strangePrinter(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        return helper(0,n-1,s);
    }
};