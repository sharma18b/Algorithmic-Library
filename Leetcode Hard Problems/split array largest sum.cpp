class Solution {
public:
    bool split(int mid,vector<int>& nums, int m)
    {
        int temp =0,n = nums.size(),count = 0;
        for (int i=0;i<n;i++)
        {
            if(nums[i] > mid) return false;
            temp += nums[i];
            if(temp > mid)
            {
                count++;
                temp = nums[i];
            }
        }
        count++;
        if(count <= m) return true;
        return false;
    }

    int splitArray(vector<int>& nums, int m) {
        int sum =0,n = nums.size();
        for (int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(m==1) return sum;
        int currans = 0;
        int lo = *max_element(nums.begin(),nums.end());
        int hi = sum;
        while(lo <= hi)
        {
            int mid = (lo+hi)/2;
            if(split(mid,nums,m))
            {
                currans = mid;
                hi = mid - 1;
            }
            else lo = mid+1;

        }
        return currans;

    }
};
