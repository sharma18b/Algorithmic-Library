class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;
        int last0=0,last1=0,last2 = 0;
        for (int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                last0 = (2*last0 + 1)%mod;
            }
            else if(nums[i]==1)
            {
                last1 = (2*last1 + last0)%mod;
            }
            else
            {
                last2 = (2*last2 + last1)%mod;
            }
        }
        return last2;
        
    }
};