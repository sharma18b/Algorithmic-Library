class Solution {
public:
    vector<int> nsl(vector<int> &h)
    {
        int n = h.size();
        vector<int> ans(n,-1);
        //return ans;
        int i = n-1;
        stack<int> s;
        while(i >= 0)
        {
            int j = i;
            if(s.empty() || h[s.top()] <= h[i]) s.push(i),i--;
            else
            {
                int temp = s.top();
                s.pop();
                ans[temp] = i;
            }
        }
        return ans;
    }
    vector<int> nsr(vector<int>&h)
    {
        int n = h.size();
        vector<int> ans(n,n);
        int i = 0;
        stack<int> s;
        //return ans;
        while(i < n)
        {
            if(s.empty() || h[s.top()] <= h[i]) s.push(i),i++;
            else
            {
                int temp = s.top();
                s.pop();
                ans[temp] = i;
            }
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0,n = heights.size();
        if(n==0) return 0;
        if(n==1) return heights[0];
        vector<int> l = nsl(heights);
        vector<int> r = nsr(heights);
        for (int i=0;i<n;i++)
        {
            ans = max(ans,(r[i] - l[i] - 1)*heights[i]);
        }
        return ans;


    }
};
