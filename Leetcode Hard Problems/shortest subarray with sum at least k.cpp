class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0) return -1;
        int currsum = 0;
        int best = INT_MAX;
        int j=0,i=0;
        currsum += nums[j++];
        while( i < n)
        {
            if(j < n && currsum < k)
            {
                currsum += nums[j++];
            }
            else 
            {
                if(currsum==k)
                {
                    best = min(best , j - i);
                }
                if(i < n) currsum -= nums[i++];
            }
        }
        return best==INT_MAX ? -1 : best;
        
    }
};