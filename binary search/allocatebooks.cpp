bool feasiblepagesforeachstudent(vector<int> A,int limit,int B)
{
    int sum = 0,cnt = 1;
    for (int i=0;i<A.size();i++)
    {
        sum+=A[i];
        if(sum > limit)
        {
            sum = A[i];
            cnt++;
        }
        if(cnt > B) return false;
    }
    return true;
}


int Solution::books(vector<int> &A, int B) {
    int n = A.size();
    if (B > n) return -1;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+= A[i];
    }
    long long int ans = INT_MAX;
    int low = *max_element(A.begin(),A.end());
    int high = sum;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(feasiblepagesforeachstudent(A,mid,B))
        {
            ans = mid;
            high = mid-1;
        }
        else low = mid + 1;
    }
    return ans;

}
