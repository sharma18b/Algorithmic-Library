

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int n = A.size();
    int m = B.size();
    vector<int> totcost(20020,INT_MAX);
    totcost[0] = 0;
    for (int i = 0 ; i <= 1000 ; i++)
    {
        for (int j =0 ; j < m; j++)
        {
            if ( i + B[j] <= 1000)
            {
                totcost[i + B[j]] = min(totcost[i + B[j]] , totcost[i] + C[j]);
            }
        }
    }
    int ans =0;
    for (int i=0;i<n;i++) ans += totcost[A[i]];
    return ans;
}
