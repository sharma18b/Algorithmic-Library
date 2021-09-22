class Solution {
public:
    static bool comp(const vector<int> &a,vector<int> &b)
    {
        return a[1] < b[1];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size(),val;
        vector<vector<int>> jobs;
        for (int i=0;i<n;i++)
        {
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end(),comp);
        vector<int> dp(n+1,0);
        dp[0] = jobs[0][2];
        for (int i=1;i<n;i++)
        {
            int inc  = jobs[i][2];
            int exc = 0;
            int last = -1;
            int high = i-1,low = 0;
            while(low<=high)
            {
                int mid = (low + high)/2;
                if(jobs[mid][1] <= jobs[i][0])
                {
                    last = mid;
                    low = mid+1;
                }
                else high = mid-1;
            }
            if(last!=-1)
            {
                inc += dp[last];
            }
            exc = dp[i-1];
            dp[i] = max(inc,exc);
        }
        return dp[n-1];
    }
};