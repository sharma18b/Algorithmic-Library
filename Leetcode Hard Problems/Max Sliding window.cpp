class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> m;
        int n = nums.size();
        for (int i=0;i<k;i++) m[nums[i]]++;
        vector<int> res(n-k+1);
        res[0] = (*m.rbegin()).first;
        for (int i=0;i<nums.size()-k;i++)
        {
            if(m[nums[i]] > 1)
            {
                m[nums[i]]--;
            }
            else
            {
                m.erase(nums[i]);
            }
            m[nums[i+k]]++;
            res[i+1] = (*m.rbegin()).first;
        }
        return res;
    }
};
