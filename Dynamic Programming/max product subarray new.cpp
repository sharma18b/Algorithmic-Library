int Solution::maxProduct(const vector<int> &A) {
    int currmin = 1,currmax = 1,n = A.size();
    int ans = 0,flag = 0;
    if(n==1) return A[0];
    for (int i=0;i<n;i++)
    {
        if(A[i] > 0)
        {
            flag = 1;
            currmax = max(A[i],currmax*A[i]);
            currmin = min(A[i],currmin*A[i]);
        }
        else if(A[i]==0)
        {
            currmax = A[i];
            currmin = A[i];
        }
        else
        {
            swap(currmax,currmin);
            currmin = min(A[i],currmin*A[i]);
            currmax = max(A[i],currmax*A[i]);
        }
        ans = max(ans,max(currmax,A[i]));
    }
    if(flag==1 && ans==0) return 0;
    return ans;
}
