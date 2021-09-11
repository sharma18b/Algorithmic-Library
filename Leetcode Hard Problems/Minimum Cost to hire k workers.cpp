class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<vector<double>> workers;
        int n = quality.size(),inf = INT_MAX;
        for (int i=0;i<n;i++)
        {
            workers.push_back({(double)(wage[i])/quality[i] , (double)quality[i]});
        }
        sort(workers.begin(),workers.end());
        priority_queue<double> pq;
        double currsum = 0;
        double ans = inf;
        for (auto i : workers)
        {
            currsum += i[1];pq.push(i[1]);
            if (pq.size() > k) currsum -= pq.top(),pq.pop();
            if(pq.size()==k) ans = min(ans , currsum * i[0]);
        }
        return ans;
    }
};