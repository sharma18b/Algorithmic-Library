class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(),p;
        if (n==0) return 0;
        int avoid  = 0,take =nums[0];
        for (int i=1;i<n;i++)
        {
            p = take;
            take = avoid + nums[i];
            avoid = max(avoid,p);
        }
        return max(avoid,take);
    }
};