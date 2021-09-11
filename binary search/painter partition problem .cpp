int feasiblepainter(vector<int> A,int limit){
    int sum = 0,cnt =1;
    for (int i=0;i<A.size();i++)
    {
        sum+=A[i];
        if(sum > limit) sum=A[i],cnt++;
    }
    return cnt;
}


int Solution::paint(int A, int B, vector<int> &C) {
    int n = C.size();
    int totallength = 0,l = *max_element(C.begin(),C.end());
    for (int i=0;i<n;i++)
    {
        totallength += C[i];
    }
    int low = l;
    int high = totallength;
    long long int ans=-1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        int feasible = feasiblepainter(C,mid);
        if(feasible <= A)
        {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return (ans*B)%10000003;
}
