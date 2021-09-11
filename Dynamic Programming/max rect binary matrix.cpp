vector<int> nsl(vector<int> a,int n)
{
    stack<int> s;
    vector<int> res(n,-1);
    int i=n-1;
    while(i>=0)
    {
        if(s.empty() || a[s.top()] <= a[i] ) s.push(i--);
        else
        {
            int t = s.top();
            s.pop();
            res[t] = i;
        }
    }
    return res;
}



vector<int> nsr(vector<int> a,int n)
{
    stack<int> s;
    vector<int> res(n,n);
    int i=0;
    while(i<n)
    {
        if(s.empty() || a[s.top()] <= a[i] ) s.push(i++);
        else
        {
            int t = s.top();
            s.pop();
            res[t] = i;
        }
    }
    return res;
}


int histarea(vector<int> a,int n)
{
    int ans = 0,curr;
    vector<int> left = nsl(a,n);
    vector<int> right = nsr(a,n);
    for (int i=0;i<n;i++)
    {
        curr = a[i] * (right[i] - left[i] - 1);
        ans = max(ans ,curr);
    }
    return ans;
}


int Solution::maximalRectangle(vector<vector<int> > &A) {
    int n = A.size(),m  = A[0].size();
    vector<int> a(m,0);
    int currarea = 0,maxarea =0;
    for (int i=0;i<n;i++)
    {
        for (int j =0 ;j<m;j++)
        {
            if(A[i][j]==0) a[j]=0;
            else a[j]+=A[i][j];
        }
        currarea = histarea(a,m);
        maxarea= max(currarea,maxarea);
    }
    return maxarea;
}
