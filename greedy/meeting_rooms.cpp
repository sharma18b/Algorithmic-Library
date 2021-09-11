int Solution::solve(vector<vector<int> > &A)
{
    int n = A.size(),ans  = 0,curr = 0;
    map<int,int> m;
    for (int i=0;i<n;i++){
        m[A[i][0]]++;
        m[A[i][1]]--;}
    for (auto i : m)
    {
        curr += i.second;
        ans = max(curr,ans);
    }
    return ans;
}
