class Solution {
public:
    static bool comp(vector<int> &a,vector<int>&b)
    {
        return a[1] < b[1];
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int m = rides.size();
        sort(rides.begin(),rides.end(),comp);
        vector<long long> dp(m);
        long long inc=0,exc=0;
        dp[0] = rides[0][1] - rides[0][0] + rides[0][2];
        for (int i=1;i<m;i++)
        {
            inc = rides[i][1] - rides[i][0] + rides[i][2];
            int last = -1,low = 0,high = i-1;
            while(low <= high)
            {
                int mid = (low+high)/2;
                if(rides[mid][1] <= rides[i][0])
                {
                    last = mid;
                    low = mid + 1;
                }
                else high = mid - 1;
            }
            if(last != -1)
            {
                inc += dp[last];
            }
            exc = dp[i-1];
            dp[i] = max(exc,inc);
        }
        return dp[m-1];
    }
};