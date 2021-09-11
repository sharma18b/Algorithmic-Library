class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0,n = intervals.size();
        if(n==0)
        {
            ans.push_back(newInterval);
            return ans;
        }
        if(newInterval[1] < intervals[0][0])
        {
            ans.push_back(newInterval);
            while(i < n)
            {
                ans.push_back(intervals[i]);
                i++;
            }
            return ans;
        }
        while(i < n && intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }
        if(i==n)
        {
            ans.push_back({newInterval[0],newInterval[1]});
            return ans;
        }
        int curr_start = min(newInterval[0],intervals[i][0]);
        while(i < n && intervals[i][0] <= newInterval[1])
        {
            i++;
        }
        int curr_end = max(newInterval[1],intervals[i-1][1]);
        ans.push_back({curr_start,curr_end});
        while(i < n) ans.push_back(intervals[i]),i++;
        return ans;
    }
};
