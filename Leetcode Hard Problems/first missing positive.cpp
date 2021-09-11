class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> m;
        for (auto i : nums)m[i]++;
        for(int i=0;i<nums.size();i++)
        {
            if(m.count(i+1)) continue;
            else return i+1;
        }
        return nums.size() + 1;
    }
};
