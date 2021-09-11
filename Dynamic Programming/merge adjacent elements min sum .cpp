int merge(vector<vector<int>> &dp,vector<int> A,int i,int j)
{
    if(i==j)
    {
        return 0;
    }
    if(dp[i][j]!=0) return dp[i][j];
    dp[i][j] = INT_MAX;
    int sum = 0;
    for (int k=i;k<=j;k++)
    {
        sum += A[k];
    }
    for (int k=i;k<j;k++)
    {
        dp[i][j] = min(dp[i][j] , sum + merge(dp,A,i,k) + merge(dp,A,k+1,j));
    }
    return dp[i][j];
}

int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> dp(n,vector<int> (n,0));
    return merge(dp,A,0,n-1);

}
