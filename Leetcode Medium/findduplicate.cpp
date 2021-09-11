class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> a(100002,0);int n = nums.size();
        for (int i=0;i<n;i++)
        {
            a[nums[i]]++;
            if(a[nums[i]] > 1) return nums[i];
        }
        return -1;

    }
};
