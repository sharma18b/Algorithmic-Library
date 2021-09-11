class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(),ans = 1,z=0;
        vector<int> k;
        vector<int> res(n,0);
        for (int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                z++;
                if(z>1) return res;
                k.push_back(i);
            }
            else ans*=nums[i];
        }
        if (z==0)
        {
            for (int i=0;i<n;i++)
            {
               res[i] = ans/nums[i];
            }
        }
        else
        {
            res[k[0]] = ans;
        }

        return res;

    }
};
