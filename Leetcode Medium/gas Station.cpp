class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(),curr;
        for (int i=0;i<n;i++)
        {
            curr = gas[i];
            if(cost[i] > gas[i]) continue;
            for (int j = 0;j<n;j++)
            {
                curr += (gas[(i + j + 1)%n] - cost[(i + j)%n]);
                if(curr < cost[(i + j + 1)%n]) break;
                if(j==n-1) return i;
            }
        }
        return -1;
    }
};