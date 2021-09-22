class Solution {
public:
    static bool comp(const vector<int> &a,const vector<int> &b)
    {
        return a[2] > b[2];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int ans =0;
        for (int i=0;i<n;i++)
        {
            costs[i].push_back(costs[i][0] - costs[i][1]);
        }
        sort(costs.begin(),costs.end(),comp);
        for (int i=0;i<n/2;i++)
            ans += costs[i][1];
        for (int i=n/2;i<n;i++)
            ans += costs[i][0];
        return ans;
    }
};