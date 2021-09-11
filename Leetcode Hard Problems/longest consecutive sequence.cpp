class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> m;
        vector<bool> vis(n,false);int j=0;
        for(auto i : nums) m[i]=j,j++;
        for (int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                int curr = nums[i],left = nums[i];
                while(m.find(curr+1)!=m.end())
                {
                    vis[m[curr+1]] = true;
                    curr++;
                }
                while(m.find(left-1)!=m.end())
                {
                    vis[m[left-1]] = true;
                    left--;
                }
                ans = max(ans,curr - left + 1);
            }

        }
        return ans;
    }
};
