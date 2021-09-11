int subArraysWithSumZero(vector<int> a,int n)
{
    int res = 0;
    map<int,int> m;
    int currsum = 0;
    for (int i=0;i<n;i++)
    {
        currsum += a[i];
        if(currsum == 0) res++;
        if(m.count(currsum))
        {
            res+=m[currsum];
        }
        m[currsum]++;
    }
    return res;
}



int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int ans =0;
    if(n==0 || m==0) return 0;
    for (int i=0;i<m;i++)
    {
        vector<int> a(n,0);
        for (int j=i;j<m;j++)
        {
            for (int k=0;k<n;k++)
            {
                a[k] += A[k][j];
            }
            ans += subArraysWithSumZero(a,n);
        }
    }
    return ans;
}
