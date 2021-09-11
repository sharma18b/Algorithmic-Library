class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int cs = 0,s = -1,e = -1,ans =0;
        for (int i=0;i<nums.size();i++)
        {
            cs += nums[i];
            if(cs==k) ans++;
            if(m.find(cs-k)!=m.end()) ans+=m[cs-k];
            m[cs]++;
        }
        return ans;
    }
};
