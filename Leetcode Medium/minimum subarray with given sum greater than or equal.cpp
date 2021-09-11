class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(),sum =0;
        if(n==0) return 0;
        if(n==1) return target==nums[0] ? 1 : 0;
        for (int i=0;i<n;i++) sum+=nums[i];
        if(sum < target) return 0;
        if(sum==target) return n;
        int i=0,ans = n+1,currsum=0;
        for (int j=0;j<n;j++)
        {
            currsum += nums[j];
            while(currsum >= target)
            {
                ans = min(ans,j - i + 1);
                currsum -= nums[i++];
            }
        }
        return ans==n+1 ? 0 : ans;
    }
};
