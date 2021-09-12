

int Solution::solve(const vector<int> &A) {
    int n=A.size();int sum=0;
    for(int i=0; i<n; i++) sum+=A[i];
    sum/=2;
    int dp[n+1][sum+1];


    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(i==0) dp[i][j]=INT_MAX-2;
            if(j==0) dp[i][j]=0;


        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(j>=A[i-1]){
                dp[i][j]= min(1+dp[i-1][j-A[i-1]],dp[i-1][j]);
            }
            else
            dp[i][j]=dp[i-1][j];

        }
    }
    if(dp[n][sum]==INT_MAX-2){
        // return 3;
        int i=n;
        for(int j=sum; j>=0; j--){
            if(dp[i][j]<INT_MAX-2) return dp[i][j];
        }

    }
    return dp[n][sum];


    // recursive approach

}
