class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n<=1) return intervals;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int cs = intervals[0][0],i = 1;
        int ce = intervals[0][1];
        while(i < n)
        {
            int s = intervals[i][0];
            int e = intervals[i][1];
            if (s <= ce) ce  = max(ce,e);
            else if (s > ce)
            {
                vector<int> temp;
                temp.push_back(cs);temp.push_back(ce);
                cs = s;ce = e;
                ans.push_back(temp);
            }
            i++;
        }
        vector<int> temp;
        temp.push_back(cs);temp.push_back(ce);
        ans.push_back(temp);
        return ans;

    }
};
